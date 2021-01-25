#include <iostream>
#include <string>

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned noCnt = 0, spaceCnt = 0, tabCnt = 0, newCnt = 0;
    std::string ch;
    while (getline(std::cin, ch))
    {
        for(int i = 0; i < ch.size(); i++)
        {
            switch (tolower(ch[i])) 
            {
                case 'a':
                    ++aCnt;
                    break;
                case 'e':
                    ++eCnt;
                    break;
                case 'i':
                    ++iCnt;
                    break;
                case 'o':
                    ++oCnt;
                    break;
                case 'u':
                    ++uCnt;
                    break;
                case ' ':
                    ++spaceCnt;
                    break;
                case '\t':
                    ++tabCnt;
                    break;
                case '\n':
                    ++newCnt;
                    break;
                default:
                    ++noCnt;
                    break;
            }
        }
    }
    std::cout << "Number of vowel a: \t" << aCnt << '\n'
            << "Number of vowel e: \t" << eCnt << '\n' 
            << "Number of vowel i: \t" << iCnt << '\n' 
            << "Number of vowel o: \t" << oCnt << '\n'
            << "Number of vowel u: \t" << uCnt << '\n'
            << "Number of space: \t" << spaceCnt << '\n'
            << "Number of tab: \t" << tabCnt << '\n'
            << "Number of new line: \t" << tabCnt << '\n'
            << "Number of non-vowel: \t" << noCnt << std::endl;
    
    return 0;
}