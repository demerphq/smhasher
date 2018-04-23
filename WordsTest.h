#include "Stats.h"
#include <iostream>
#include <fstream>
template < typename hashtype >
bool WordsTest( hashfunc<hashtype> hash, double confidence) {
    std::vector<hashtype> hashes;
    std::set<std::string> words;
    std::set<std::string>::iterator it;
    std::string line;
    std::string filename= "/usr/share/dict/words";
    int count= 0;
    int lines= 0;
    Rand r(82762);
    hash.seed_state_rand(r);
    std::ifstream wordfile (filename.c_str());
    if (!wordfile.is_open())
    {
        std::cout << "Unable to open word file " << filename << "\n";
        exit(1);
    }
    while ( getline (wordfile,line) )
    {
        lines++;
        words.insert(line);
        line.append("!");
        words.insert(line);
        line.append("!");
        words.insert(line);
    }
    wordfile.close();
    hashes.resize(words.size());
    for ( it = words.begin(); it != words.end(); it++ )
    {
        line = *it;
        hash(line.c_str(),line.length(),&hashes[count++]);
    }
    printf("# Hashed %d keys from %d words from file '%s'\n",
            count, lines, filename.c_str());
    return TestHashList<hashtype>(hashes,true,confidence,false,"Keyset 'Words'");
}
