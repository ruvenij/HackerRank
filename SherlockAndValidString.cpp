#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    std::vector<int> characterCounts(26, 0);
    
    for (char character : s)
        characterCounts[character - 'a']++;

    std::vector<int> charCounts;
    bool charcterDiffDetected = false;

    for (int characterCount : characterCounts)
    {
        if (characterCount == 0) continue;
        
        if (characterCounts[0] != characterCount)
        {
            charcterDiffDetected = true;
        }

        if (charCounts.size() < (characterCount + 1))
            charCounts.resize(characterCount + 1, 0);

        charCounts[characterCount]++;
        std::cout << characterCount << " "; 
    }

    std::cout << std::endl;

    if (not charcterDiffDetected)
        return "YES";

    int maxCount = 1;
    int minCount = INT_MAX;
    int distinctCounts = 0;

    for (int i = 0; i < charCounts.size(); i++)
    {
        if (charCounts[i] == 0) continue;
        maxCount = std::max(maxCount, i);
        minCount = std::min(minCount, i);
        std::cout << charCounts[i] << " "; 
        distinctCounts++;
    }

    std::cout << std::endl;
    std::cout << minCount << " = " << maxCount <<std::endl;
    std::cout << charCounts[minCount] << " = " << charCounts[maxCount] <<std::endl;

    if (distinctCounts > 2)
        return "NO";

    if ((minCount == 1) and (charCounts[minCount] == 1))
        return "YES";
        
    if ((minCount + 1) != maxCount)
        return "NO";

    if ((charCounts[minCount] != 1) and (charCounts[maxCount] != 1))
        return "NO";
    
    return "YES";
}

int main()
{
    std::cout << isValid("abcdefghhgfedecba") << std::endl;
    std::cout << isValid("aaaabbcc") << std::endl;
    std::cout << isValid("ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd") << std::endl;
    return 0;
}