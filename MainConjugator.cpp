#include <iostream>
#include <string>
#include <locale>
#include <unordered_map>
#include <vector>
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif
using namespace std;

enum VerbType
{
    ichidan,
    godan,
};

const unordered_map<wchar_t, vector<wchar_t>> HIRAGANA_MAP = {
    // "Verb Ending" | い、あ、え、お、
    {L'う', {L'い', L'わ', L'え', L'お', L' '}},
    {L'く', {L'き', L'か', L'け', L'こ', L' '}},
    {L'ぐ', {L'ぎ', L'が', L'げ', L'ご', L' '}},
    {L'す', {L'し', L'さ', L'せ', L'そ', L' '}},
    {L'つ', {L'ち', L'た', L'て', L'と', L' '}},
    {L'ぬ', {L'に', L'な', L'ね', L'の', L' '}},
    {L'ぶ', {L'び', L'ば', L'べ', L'ぼ', L' '}},
    {L'む', {L'み', L'ま', L'め', L'も', L' '}},
    {L'る', {L'り', L'ら', L'れ', L'ろ', L' '}},
};

void DictionaryFormIntoInfinitiveForm(wstring *verb, VerbType type)
{
    int vLength = verb->length();
    if (type == ichidan)
    {
    }
    else if (type == godan)
    {
        wchar_t lastChar = verb->back();
        auto it = HIRAGANA_MAP.find(lastChar);
        wcout << lastChar << endl;
        if (it != HIRAGANA_MAP.end())
        {
            wcout << it->first << endl;
            verb->at(vLength - 1) = it->second[0];
        }
        else
        {
            wcout << L"Key not found";
        }
    }

    // wcout << L"First character: " << (*verb)[0] << endl;
    // if (type == special)
    // {
    //     if ((*verb)[0] == L'行' && (*verb)[1] != L'う')
    //     {
    //         (*verb)[1] = L'き';
    //     }
    //     else if ((*verb)[] == L'する')
    // }
}

int main()
{
    wstring verb;
    VerbType type;
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
#else
    locale::global(locale("en_US.UTF-8"));
    wcout.imbue(locale());
#endif
    // wcout << &verb;
    cout << "Enter in this format: VERB TYPE";
    wcin >> verb;
    type = godan;
    DictionaryFormIntoInfinitiveForm(&verb, type);
    wcout << verb << endl;
}
