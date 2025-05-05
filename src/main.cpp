#include <iostream>
#include <string>
#include <vector>


void box(const std::string& text)
{
    std::string line(text.size(), '-');
    std::cout << "+-" << line << "-+\n";
    std::cout << "| " << text << " |\n";
    std::cout << "+-" << line << "-+\n";
}


void arrow()
{
    std::cout << "  |\n"
                 "  v\n";
}

void decision(const std::string& question)
{
    box(question + " ?");
    std::cout << " / \\\n"
                 "v   v\n";
}

int main()
{
    box("INICIO");
    arrow();
    box("Ingresar X");
    arrow();
    decision("X > 10");
    box("Grande");
    arrow();
    box("FIN");
    return 0;
}



