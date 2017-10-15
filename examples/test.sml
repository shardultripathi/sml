// uint32_t a[100][2][3][4234][432];
// uint32_t b[100];
// uint32_t d[100];

// uint16_t x[100];
uint32_t a1;
uint32_t a2;
public uint32_t x;
x = 5;
// a1 = -a2;
// a1 = ~a2;

a1 = 92;
a1 = a1 @> 3;
for uint32_t i = [0:100] {
    for uint32_t j = [0:10] {
        x = i + j;
        a1 = x;
        a1 = a1 + x;
        if (i > j) {
            a1 = a1 + 1;
        }
    }
}

output(a1);