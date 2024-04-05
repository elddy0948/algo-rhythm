#include <stdio.h>

#define PAPER_MAX 101
#define PAPER_WIDTH 10
#define PAPER_HEIGHT 10

unsigned char paper_map[PAPER_MAX][PAPER_MAX] = {0};

void stick_paper(unsigned char x, unsigned char y)
{
  unsigned char w, h = 0;
  for (w = x; w < x + PAPER_WIDTH; ++w)
  {
    for (h = y; h < y + PAPER_HEIGHT; ++h)
    {
      paper_map[w][h] = 1;
    }
  }
}

int main(void) {
  unsigned int color_papers, i = 0;
  unsigned int x, y = 0;
  unsigned int area = 0;

  scanf("%d", &color_papers);

  for (i = 0; i < color_papers; ++i)
  {
    scanf("%d %d", &x, &y);
    stick_paper((unsigned char)x, (unsigned char)y);
  }

  for(x = 0; x < PAPER_MAX; ++x)
  {
    for(y = 0; y < PAPER_MAX; ++y)
    {
      if(paper_map[x][y] == 1)
      {
        area++;
      }
    }
  }

  printf("%d", area);

  return 0;
}
