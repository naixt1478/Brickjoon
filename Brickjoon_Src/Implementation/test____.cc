#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define BOJ

struct node {
    char str[8];
    int arr[10];

    node() {
        memset(arr, 0, sizeof arr);
        memset(str, 0, sizeof str);
    }
};

int word_sum(const char *str) {
    int sum = 0;
    for (int c = 0; str[c] != '\0' && str[c] != ' '; c++) {
        sum += str[c] - 'a' + 1;
    }
    return sum;
}

bool validate_input_1(const char *str) {
    for (int c = 0; str[c] != '\0'; c++) {
        if (str[c] < 'A' || str[c] > 'Z')
            return false;
    }
    return true;
}

bool validate_input_2(const char *str) {
    static const char key[] = "TSFHHABP", hint[] = "\\BD_OBNZ";
    for(int i = 0; i < 8; i++)
    {
        printf("%d ", key[i] - 'A');
    }
    int prv = 0;
    /*int prv2 = 0;
    vector<int> prv_;
    prv_.emplace_back(0);
    for(int i = 0; i < 8; i++)
    {
        for(auto prv__ : prv_)
        {
            printf("|%d, %d|:\n",i, prv__);
            for(char j = 'A'; j <= 'Z'; j++)
            {
                prv2 = ((prv << 1) ^ j) & 31;
                if (prv2 + 'A' == key[i])
                {
                    printf("%c ",j);
                    prv_.emplace_back(prv2);
                }
            }
            printf("\n");
        }
    }
    */
    prv = 0;
    for (int i = 0; i < 8; i++) {
        int origin = prv;
        prv = ((prv << 1) ^ str[i]) & 31;
        if (prv + 'A' != key[i])
        {
            printf("not pass : %d, diff : %d, origin : %d\n",i, key[i] - 'A', origin);
            return false;
        }
    }
// 0 : 19 != prv A
// 1 : 18 != prv A
// 2 : 5 != prv A
// 3 : 7 != prv A
// 4 : 7 != prv A
// 5 : 0 != prv B
// 6 : 1 != prv A
// 7 : 15 != prv A

    for (int i = 0; i < 8; i++) {
        printf("%c", (char)(str[i] ^ hint[i] & 31));
    }
    printf("\n");

    return true;
}

bool validate_input_3(const int *arr) {
    static const char s1[] = "computer preferred bulk tourist biographies";
    static const char s2[] = "worldwide resistance implemented magical viruses";
    static const char s3[] = "theorem";

    static auto sentence_sum = [&](const char *str) {
        int sum = 0;
        for (int c = 0; str[c] != '\0'; c++) {
            sum *= 100;
            sum += word_sum(str + c) % 100;
            while (str[c] != ' ' && str[c] != '\0')
                c++;
            if (str[c] == '\0')
                break;
        }
        return sum;
    };

    if (arr[0] != sentence_sum(s1))
        return false;
    if (arr[1] != sentence_sum(s2))
        return false;
    if (arr[2] != sentence_sum(s3))
        return false;

    return true;
}

int main() {
    node data;

    int *arr = data.arr;
    char *str = data.str;

    scanf("%s", str);

#ifndef BOJ
    printf("Please run this code on a similar environment to:\n");
    printf("https://help.acmicpc.net/judge/info\n");
    printf("\n");
    printf("After reading the article above, please uncomment the 6th line:\n");
    printf("#define BOJ\n");
    return 1;
#endif

    if (!validate_input_1(str)) {
        printf("NO (1)\n");
        return 1;
    }
    if (!validate_input_2(str)) {
        printf("NO (2)\n");
        return 1;
    }
    if (!validate_input_3(arr)) {
        printf("NO (3)\n");
        return 1;
    }

    printf("YES\n");
    return 0;
}
