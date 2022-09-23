#include "dotenv.h"

#include "environ.h"
#include "Parser.h"

#include <fstream>
#include <utility>


using namespace std;
using namespace dotenv;


dotenv::cdotenv& dotenv::cdotenv::load_dotenv(const string& dotenv_path, const bool overwrite, const bool interpolate)
{
    ifstream env_file;
    env_file.open(dotenv_path);

    if (env_file.good())
    {
        Parser parser;
        parser.parse(env_file, overwrite, interpolate);
        env_file.close();
    }

    return *this;
}


const dotenv::cdotenv::value_type dotenv::cdotenv::operator[](const key_type& k) const
{
    return getenv(k).second;
}


dotenv::cdotenv& dotenv::cdotenv::instance()
{
    return _instance;
}


const string dotenv::cdotenv::env_filename = ".env";
dotenv::cdotenv dotenv::cdotenv::_instance;

dotenv::cdotenv& dotenv::env = cdotenv::instance();
