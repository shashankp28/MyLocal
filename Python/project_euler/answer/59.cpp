#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

string decrypt(std::vector<char> &message, string key)
{
    if (key.size() != 3)
        return "Invalid Key!";
    string result = "";
    for (int i = 0; i < (int)message.size(); i += 3)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i + j < (int)message.size())
            {
                result += static_cast<unsigned char>(message[i + j] ^ key[j]);
            }
        }
    }
    return result;
}

bool checkEnglish(string &target)
{
    for (auto ch : target)
    {
        bool valid = (ch - 'A' <= 25) || (ch - 'a' <= 25) || (ch - '0' <= 9);
        valid = valid ||  (ch - ' ' <= 15);
        if (!valid)
            return false;
    }
    return true;
}

int asciiSum(string &target)
{
    int total = 0;
    for (auto ch : target)
    {
        total += ch;
    }
    return total;
}

int main()
{
    std::ifstream file("./files/0059_cipher.txt");
    std::vector<char> message;

    if (file)
    {
        std::string line;
        if (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string token;

            while (std::getline(ss, token, ','))
            {
                message.push_back(static_cast<char>(std::stoul(token)));
            }
        }
    }
    else
    {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    for (char i = 'a'; i <= 'z'; i++)
    {
        for (char j = 'a'; j <= 'z'; j++)
        {
            for (char k = 'a'; k <= 'z'; k++)
            {
                string key;
                key += i;
                key += j;
                key += k;
                string output = decrypt(message, key);
                if (checkEnglish(output))
                {
                    cout << "Key: " << key << "\n";
                    cout << "Sum: " << asciiSum(output) << "\n";
                    cout << "Output: " << output << "\n\n";
                }
            }
        }
    }

    return 0;
}
