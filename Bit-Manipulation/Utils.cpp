#include "Utils.h"

void writeBit(int *N, int k, int kthBit) {
    (*N) = ((*N) & (~(1 << k))) | (kthBit << k);
}

int insertion(int M, int N, int i, int j) {
    int bitNumber = j - i + 1;
    for(int k = 0; k < bitNumber; k++) {
        int kthBit = ((M & (1 << k)) != 0) ? 1 : 0;
        writeBit(&N, k + i, kthBit);
    }
    return N;
}

string binaryToString(double number) {
    string result = "0.";

    while(number != 0 && result.size() <= 32) {
        cout << "result is: " << result << endl;
        number *= 2;
        result.append(to_string(int(floor(number))));
        number -= floor(number);
    }

    if(result.size() > 32) {
        return "ERROR\n";
    }

    return result;
}

int flipBitToWin(int number) {
    int currentSeq = 0, pastSeq = 0, maxSeq = 0;
    while(true) {
        if(number & 1) {
            currentSeq++;
            pastSeq++;
        } else {
            if(maxSeq < currentSeq) {
                maxSeq = currentSeq;
                if(currentSeq == pastSeq) {
                    maxSeq++;
                }
            }
            currentSeq = pastSeq + 1;
            pastSeq = 0;
        }
        if(number == 0) {
            break;
        }
        number >>= 1;
    }
    return maxSeq;
}

pair<int, int> countSetBits(int number) {
    int counter = 0, size = 0;
    while(number > 0) {
        size++;
        counter += (number & 1) == 1 ? 1 : 0;
        number >>= 1;
    }
    return {counter, size};
}

int nextBiggestNumber(int number) {
    pair<int, int> p = countSetBits(number);
    int counter = p.first;
    int size = p.second;
    int result = 0, idx = 0;

    while(idx <  size && counter > 0) {
        result |= (1 << (size - idx - 1));
        idx++;
        counter--;
    }
    return result;
}

int nextSmallestNumber(int number) {
    pair<int, int> p = countSetBits(number);
    int result = 0, idx = 0;
    int counter = p.first, size = p.second;

    while(idx < size && counter > 0) {
        result |= (1 << idx);
        idx++;
        counter--;
    }
    return result;
}

int conversion(int a, int b) {
    int counter = 0;
    while (a != 0 && b != 0) {
        counter += ((a & 1) == (b & 1)) ? 0 : 1;
        a >>= 1;
        b >>= 1;
    }
    while(a != 0) {
        if((a & 1) != 0)
            counter++;
        a >>= 1;
    }

    while(b != 0) {
        if((b & 1) != 0)
            counter++;
        b >>= 1;
    }
    return counter;
}

int conversion2(int a, int b) {
    return countSetBits((a ^ b)).first;
}

int pairwiseSwap(int number){
    int maskOdd = 0xAAAAAAAA;
    int maskEven = 0x55555555;

    return ((number & maskOdd) >> 1 ) | ((number & maskEven) << 1);
}
