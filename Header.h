#pragma once
//biblio générales
#include <iostream>
#include <iomanip> // inclus pour std::setw pour affichage
#include <locale>
#include <codecvt>
//biblio pour la manipulation des vecteurs
#include <vector>
#include <algorithm>
//biblio pour la gestion des exceptions
#include <exception>

using namespace std;

//retour à la ligne
#define Rl cout<<endl

const std::wstring E_RED = L"\033[31m";
const std::wstring E_YELLOW = L"\033[33m";
const std::wstring E_RESET = L"\033[0m";


const std::string GREEN = "\033[92m";
const std::string DGREEN = "\033[32m";

const std::string DBLUE = "\033[34m";
const std::string BLUE = "\033[94m";
const std::string LBLUE = "\033[36m";
const std::string CYAN = "\033[96m";

const std::string YELLOW = "\033[33m";
const std::string BEIGE = "\033[93m";

const std::string MAGENTA = "\033[35m";
const std::string PINK = "\033[95m";

const std::string RESET = "\033[0m";

