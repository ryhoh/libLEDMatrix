#ifndef STRING5X7_H
#define STRING5X7_H

#include "MatrixBuffer.h"
#include "MatrixUtils.h"

class String5x7Buffer : public MatrixBuffer {
private:
  // access as "_fonts['a' - OFFSET]"
  static const int OFFSET = 0x20;
  static uint8_t _fonts[95][7];
  char *text;
  uint16_t len;

  // for scrolling
  int cur_in_chr = 0;
  int cur_text = 0;
  int shifted_line_n = 0;
  
  uint8_t toFont(char chr_num, int row_num);
  void insertOneColumnAtRightEnd(bool invert) override;

public:
  String5x7Buffer(short screen_n, char *text);
  ~String5x7Buffer();
  void reset();
  
  int distToBehind();
  int distToLeftSet();
  int distToRightSet();
  int distToAfter();
};

#endif