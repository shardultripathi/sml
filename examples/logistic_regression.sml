uint32_t w[10][785];
uint32_t x[785];
uint32_t ans[10];

// taking input
for uint32_t i = [0:10] {
    for uint32_t j = [0:785] {
        w[i][j] = input1(50);
    }
}

for uint32_t i = [0:785] {
    x[i] = input2(100);
}

for uint32_t i = [0:10] {
    ans[i] = 0;
    for uint32_t j = [0:785] {
        ans[i] = ans[i] + w[i][j]*x[j];
    }
}

uint32_t max;
max = 0;
for uint32_t i = [0:10] {
    max = (ans[i] > max) ? ans[i] : max;
}

output(max);