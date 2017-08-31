uint32_t a[100][2][3][4234][432];
uint32_t b[100];
uint32_t d[100];

uint16_t x[100];
uint32_t a1;
uint32_t a2;
a1 = -a2;
a1 = ~a2;

// for uint32_t i = [0:100] {
//     a[i] = input1(2);
// }
// for uint32_t i = [0:100] {
//     b[i] = input2(2);
// }
// for uint32_t i = [0:100] {
//     a[i] = b[i] & a[i];
// }
// uint32_t c[100];
// for uint32_t i = [0:100] {
//     c[i] = 2;
// }
// for uint32_t i = [0:100] {
//     a[i] = b[i] + c[i];
// }


// uint32_t a1;
// a1 = input1(2);
// uint32_t a2;
// a2 = input1(2);
// uint32_t a3;
// a3 = input2(2);

// a1 = (a2 & a3) + a3;

// for uint32_t i = [0:100] {
//     a[i] = input1(50);
//     b[i] = input2(60);
// }

// for uint32_t i = [0:100] {
//     c[i] = a[i] & b[i];
// }

// for uint32_t i = [0:100] {
//     a[i] = a[i] & b[i];
// }

// for uint32_t i = [0:100] {
//     d[i] = a[i] + b[i];
// }

output(24>>1);