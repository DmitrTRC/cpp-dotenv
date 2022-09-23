#pragma once


#include <string>


namespace dotenv
{
    class cdotenv
    {
    public:

        using   key_type = std::string;
        using value_type = std::string;

    public:

        cdotenv& load_dotenv(const std::string& dotenv_path = env_filename,
                            const bool overwrite = false,
                            const bool interpolate = true);

        const value_type operator[](const key_type& k) const;

    public:

        virtual ~cdotenv() = default;
        cdotenv(const cdotenv&) = delete;
        void operator=(const cdotenv&) = delete;

        static cdotenv& instance();
    
    private:

        cdotenv() = default;

    private:

        static const std::string env_filename;
        static cdotenv _instance;

    };


    extern cdotenv& env;
}
