#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <algorithm> 

#define PAIR_SIZE 2 

struct indexValuePair{
    unsigned short index = 0;
    unsigned int value = 0;
};

bool indexValuePairCompare (indexValuePair &i,indexValuePair &j) { return (i.value > j.value); }

int main(){

    std::array<indexValuePair, 26*26> charPairCounts{};
    for(int i = 1; i < charPairCounts.size(); i++){
        charPairCounts[i].index += i;
    }

    std::ifstream file("wordlistNoSpecials.txt");

    if(!file.is_open()){
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    std::string word;
    while(std::getline(file, word)){ 
        if(word.length() < PAIR_SIZE){
            continue;
        }
        for(int i = 1; i < word.length()-1; i++){
            unsigned char charValue1 = word[i-1] - 'a';
            unsigned char charValue2 = word[i] - 'a';
            unsigned short pairIndex = (charValue1 * 26) + charValue2;
            if(pairIndex > 26*26){
                printf("%s%s", word[i-1], word[i]);
            }
            charPairCounts[pairIndex].value++;
        }
    }
    file.close();

    for(int i=0; i < charPairCounts.size(); i++){
        unsigned char charValue1 = i/26;
        unsigned char charValue2 = i - charValue1*26;
        printf("%d:%c%c: %d\n", i+1, charValue1+'a', charValue2+'a', charPairCounts[i].value);
    }

    std::sort(charPairCounts.begin(), charPairCounts.end(), indexValuePairCompare);
    for(int i=0; i < charPairCounts.size(); i++){
        unsigned char charValue1 = charPairCounts[i].index/26;
        unsigned char charValue2 = charPairCounts[i].index - charValue1*26;
        printf("%d:%c%c: %d\n", charPairCounts[i].index+1, charValue1+'a', charValue2+'a', charPairCounts[i].value);
    }

    return 0;
}