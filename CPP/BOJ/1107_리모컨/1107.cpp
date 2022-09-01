#include <iostream>
#include <vector>
#include <algorithm>

int InputChannel()
{
  int channel;
  std::cin >> channel;
  return channel;
}

void InputRemoteControllerInfo(std::vector<bool> &remoteControllerNumbers)
{
  int numberOfBroken;
  std::cin >> numberOfBroken;

  for (int i = 0; i < numberOfBroken; i++)
  {
    int brokenNumber;
    std::cin >> brokenNumber;
    remoteControllerNumbers[brokenNumber] = false;
  }
}

int JustNumberPad(int targetChannel, std::vector<bool> &remoteController)
{
  if (targetChannel == 0)
  {
    if (!remoteController[0])
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }

  int pressCount = 0;

  while (targetChannel > 0)
  {
    if (!remoteController[targetChannel % 10])
    {
      return 0;
    }
    targetChannel /= 10;
    pressCount++;
  }

  return pressCount;
}

int UpAndDownChannel(int targetChannel, std::vector<bool> &remoteController)
{
  int minimumPress = std::abs(targetChannel - 100);

  for (int i = 0; i <= 1000000; i++)
  {
    int currentChannel = i;
    int justNumberPress = JustNumberPad(currentChannel, remoteController);
    if (justNumberPress > 0)
    {
      int upAndDownPressCount = std::abs(currentChannel - targetChannel);
      minimumPress = std::min(minimumPress, justNumberPress + upAndDownPressCount);
    }
  }

  return minimumPress;
}

int main()
{
  int channelToWatch = InputChannel();
  std::vector<bool> remoteControllerNumbers(10, true);

  InputRemoteControllerInfo(remoteControllerNumbers);

  int justNumberPressCount = JustNumberPad(channelToWatch, remoteControllerNumbers);

  std::cout << UpAndDownChannel(channelToWatch, remoteControllerNumbers);

  return 0;
}