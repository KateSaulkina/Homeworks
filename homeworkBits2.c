int bitAnd(int x, int y){
    return ~ (~ x | ~ y);
}

int bitXor(int x, int y){
    return ~ (x & y) & ~ (~ x & ~ y);
}

int thirdBits(void){
    int b0 = 36;
    int b1 = 73;
    int b2 = 146;
    int b3 = 36;
    return (b3 << 24) | (b2 << 16) | (b1 << 8) | b0;
}

int fitsBits(int x, int n){
    int m = (1 << (n + ~0)) + ~ 0;
    int nm = ~ m;
    return !((x & m) ^ x) | !((x & nm) ^ nm);
}

int sign(int x){
    int f1 = !!(x ^ 0);
    int f2 = x >> 31;
    return f1 | f2;
}

int getByte(int x, int n){
    int intShift = n << 3;
    return ((x & (255 << intShift)) >> intShift) & 255;
}

int logicalShift(int x, int n){
    int m = ~ ((~ (1 << n)) << (32 - (!n & 1) + (~ n + 1)));
    return (x >> n) & (m);
}

int addOK(int x, int y){
    int m = 1 << 31;
    int s = x + y;
    return !!((m & x) ^ (m & y)) | !((m & s) ^ (m & x));
}

int bang(int x){
    int m = 1 << 31;
    return ((m & ~ ((m & x) | ((~ x +1) & m))) >> 31) & 1;
}

int conditional(int x, int y, int z){
    int k = ~ (!! x) + 1;
    return (k & y) | ((~ k) & z);
}

int isPower2(int x){
    return !((1 << 31) & x) & !(((x + ~0) & (~ x)) ^ (x + ~0)) & !!x;
}
