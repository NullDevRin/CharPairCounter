#include <iostream>
#include <fstream>
#include <string>
#include <array>

#define PAIR_SIZE 2 

int main(){

    std::array<unsigned int, 26*26> charPairCounts{0};

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
            charPairCounts[pairIndex]++;
        }
    }
    file.close();

    for(int i=0; i < charPairCounts.size(); i++){
        unsigned char charValue1 = i/26;
        unsigned char charValue2 = i - charValue1*26;
        printf("%d:%c%c: %d\n", i+1, charValue1+'a', charValue2+'a', charPairCounts[i]);
    }

    return 0;
}