#include <iostream>
#include <regex>
#include <string>
using namespace std;

void printMatches(string str,regex reg){
    smatch matches;
    while(regex_search(str,matches,reg)){      
        cout<<matches.str(1)<<"\n";//first match
        str=matches.suffix().str();
    }    
}


int main(){

    string str1= "Cat Cats";
    regex reg1("([Cat]+s?)");
    // printMatches(str1, reg1);

    string str2= "doctor doctors doctor's";
    regex reg2("([doctor]+['s]*)");
    // printMatches(str2, reg2);

    string str3= "Just some words\n"
            "and some more\r\n"
            "and more\n";
    regex reg3("[\r]?\n");
    string newWord=regex_replace(str3,reg3," ");
    // cout<<newWord;

    //Lazy/greddy matching

    string str4="<name> Life On Mars</name>"
                "<name> Freaks and Geeks</name>";
    // regex reg4("<name>(.*)</name>");//grabs only the biggest match
    regex reg4("<name>(.*?)</name>");//lazy match: the smallest amount that can be grabbed: *? +? {n,}? 
    // printMatches(str4,reg4);

    //word boundaries
    // \\b matches start or end of a word

    string str5= "ape at the apex";
    regex reg5("(\\bape\\b)");//grabs the first ape
    // printMatches(str5, reg5);

    //string boundary
    // ^ matches the beginning of a string. outside a bracker
    // $ end of a string

    string str6= "Match everything up to @";
    regex reg6("(^.*[^@])");
    // printMatches(str6, reg6);

    string str7= "@ Get this string";
    regex reg7str7("([^@\\s].*$)");
    // printMatches(str7, reg7str7);

    string str8= "206-709-3100 202-456-1111 212-832-2000";
    regex reg8(".{3}-(.{8})");
    // printMatches(str8, reg8);

    //separate sub expression
    //get individual numbers
    string str9= "My number is 904-285-3700";
    regex reg9("(.{3})-(.*)-(.*)");
    smatch matches;
    if(regex_search(str9, matches, reg9)){
        for(int i=1; i<matches.size();i++){
            cout<<matches[i]<<endl;
        }
    }
    


    

    return 0;
}