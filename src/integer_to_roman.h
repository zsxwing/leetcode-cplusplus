class Solution {
public:
  string intToRoman(int num) {
    string roman = "";
    int scale = 1000;
    char symbol[] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
    for (int i = 0; i < 7; i += 2) {
      if (num >= scale) {
        int digit = num / scale;
        if (digit == 4) {
          roman += symbol[i];
          roman += symbol[i - 1];
        } else if (digit == 9) {
          roman += symbol[i];
          roman += symbol[i - 2];
        } else if (digit >= 5) {
          roman += symbol[i - 1];
          roman.append(digit - 5, symbol[i]);
        } else {
          roman.append(digit, symbol[i]);
        }
      }
      num %= scale;
      scale /= 10;
    }
    return roman;
  }
};
