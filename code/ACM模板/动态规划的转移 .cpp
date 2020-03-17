inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline void add(int &x, const int y) {(x += y) >= mod ? x -= mod : 0;}
inline void sub(int &x, const int y) {(x -= y) < 0 ? x += mod : 0;}