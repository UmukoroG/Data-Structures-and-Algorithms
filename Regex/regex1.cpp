#include <iostream>
#include <regex>
#include <string>
using namespace std;

void printMatches(string str,regex reg){
    smatch matches;
    cout<<boolalpha;
    while(regex_search(str,matches,reg)){
        cout<<"Is there a match: " <<
            matches.ready() << "\n";
        cout<<"Are there no matches: "<<
            matches.empty() << "\n";
        cout<<"Number of matches: "<<
            matches.size() << "\n";
        cout<<matches.str(1)<<"\n";//first match
        str=matches.suffix().str();
        cout<<endl;
    }    
}

void printMatches2(string str, regex reg){
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;

    while(currentMatch != lastMatch){
        smatch match=*currentMatch;
        cout<<match.str() << endl;
        currentMatch++;
    }
    cout<<endl;
}

int main(){

    // [ ]   : Match what is in the brackets
    // [^ ]  : Match anything not in the brackets
    // .     : Match any 1 character or space
    // +     : Match 1 or more of what proceeds
    // ()    : Return only what is between ()
    // ?     : Matches 0 or 1 character

    string str="The ape was at the apex";
    regex reg_exp("(ape[^ ]?)");//matches ape + 0 or 1 letter, no space
    // printMatches(str, reg_exp);

    string str2="I picked the pickle";
    regex reg_exp2("(pick([^ ]+)?)");

    string str3="Cat rat mat fat pat";
    // regex reg_exp3("[crmfp]at");
    regex reg_exp4("[C-Fc-f]at"); // Cat and fat
    // printMatches2(str3, reg_exp4);

    string str6="Cat rat mat fat pat";
    regex reg_exp6 ("([Cr]at)");
    string owlFood= regex_replace(str6, reg_exp6, "Owl");
    // cout<<owlFood<<endl;

    // string str7="F.B.I. I.R.S. CIA";
    // regex reg_exp7 ("([^ ]\..\..\.)");
    // printMatches2(str7, reg_exp7);

    //match whitespace

    string str8="This is a\n multiline string\n" "thas has many lines";
    regex reg_exp8("\n");
    // cout<<str8 <<endl;

    string noLBStr= regex_replace(str8, reg_exp8, " ");
    // cout<<noLBStr;

    // \d [0-9] only numbers
    // \D [^0-9] anything except a number

    string str9="12345";
    regex reg9("\\d");
    string str10="123 1234 12345 123456 1234567";
    regex reg10("\\d{5,7}");//numbers 5-7 digits long
    // printMatches2(str10, reg10);

    // \w [a-xA-Z0-9_]
    // \W [^a-xA-Z0-9_] anything except a-xA-Z0-9_

    string str11="412-867-5309";
    regex reg11("(\\w{3}-\\w{3}-\\w{4})");
    // printMatches2(str11, reg11);

    // \s [\f\n\r\t\v]
    // \S [^\f\n\r\t\v]

    string str12="John Lewis";
    regex reg12("\\w{2,20}\\s\\w{2,20}");
    // printMatches2(str12, reg12);

    string str13="a as ape bug";
    regex reg13("a[a-z]+");
    // printMatches2(str13, reg13);

    string str14="a as ape bug";
    regex reg14("a[a-z]+");
    // printMatches2(str14, reg14);

    string str15="db@aol.com m@.com @apple.com db@.com";
    regex reg15("[\\w._%+-]{1,20}@[\\w.-]{2,20}.[a-zA-Z]{2,3}");
    printMatches2(str15, reg15);

    
    return 0;
}