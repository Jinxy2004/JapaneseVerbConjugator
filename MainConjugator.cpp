#include <iostream>
#include <string>
#include <locale>
using namespace std;

enum VerbType
{
    ichidan,
    godan,
};

const unordered_map<wstring, vector<wstring>> HIRAGANA_MAP = {
    {L"う", {L"あ", L"と"}}};

void InfinitiveVerbIntoStem(wstring *verb, VerbType type)
{
    if (type == ichidan)
    {
        auto it = HIRAGANA_MAP.find(L"う");
        if (it != HIRAGANA_MAP.end())
        {
            for (const auto &val : it->second)
            {
                wcout << val << L" ";
            }
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
    wstring verb = L"行く";
    locale::global(locale("en_US.UTF-8"));
    wcout.imbue(locale());
    // wcout << &verb;
    InfinitiveVerbIntoStem(&verb, ichidan);
    // wcout << verb << endl;
}
