#include <bits/stdc++.h>
#include <openssl/md5.h>

using namespace std;

string md5_to_hex(unsigned char* md5Hash) {
    stringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)md5Hash[i];
    }
    return ss.str();
}

int computeHash(string key, int zeros) {
    unsigned char md5Hash[MD5_DIGEST_LENGTH];
    int num = 1;

    while (true) {
        stringstream ss;
        ss << key << num;
        string input = ss.str();
        
        MD5_CTX md5_ctx;
        MD5_Init(&md5_ctx);
        MD5_Update(&md5_ctx, input.c_str(), input.length());
        MD5_Final(md5Hash, &md5_ctx);

        string md5String = md5_to_hex(md5Hash);

        string reqPrefix = string(zeros, '0');
        if (md5String.substr(0, zeros) == reqPrefix) {
            return num;
        }

        num++;
    }
}

int main() {
    string key = "bgvyzdsv"; // secret key input
    int part1Res = computeHash(key, 5);
    cout << "Part 1 : " << part1Res << endl;

    int part2Res = computeHash(key, 6);
    cout << "Part 2 : " << part2Res << endl;

    return 0;
}
