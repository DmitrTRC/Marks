//
// Created by Dmitry Morozov on 22.12.2021.
//
#include "DBHandler.h"


int DataReader (const std::string &file_name) {
    std::ifstream file;
    file.open (file_name);
    if (!file.is_open ()) {
        std::cout << "File not found" << std::endl;
        return -1;
    }
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse (file, root);
    if (!parsingSuccessful) {
        std::cout << "Failed to parse configuration\n"
                  << reader.getFormattedErrorMessages ();
        return -1;
    }
    std::cout << root.toStyledString () << std::endl;
    return 0;
}

int DataReader2 (const std::string &filename) {
    Json::Value root;
    std::ifstream ifs;
    ifs.open (filename);

    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;
    JSONCPP_STRING errs;
    if (!parseFromStream (builder, ifs, &root, &errs)) {
        std::cout << errs << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << root.toStyledString () << std::endl;
    return EXIT_SUCCESS;
}

int DataWrite () {
    Mark mark ("Devops", 5, 2);
    Json::Value root;
    Json::Value data;
    constexpr bool shouldUseOldWay = false;
    root["action"] = "Add mark";
    root["user"] = "admin";
    root["data"]["value"] = mark.value;
    root["data"]["weight"] = mark.weight;
    root["data"]["subject"] = mark.subject;
    //root["marks"] = Json::parse(mark.marks.begin(), mark.marks.end(), nullptr, Json::Features::strictMode());

    ;

    if (shouldUseOldWay) {
        Json::FastWriter writer;
        const std::string json_file = writer.write (root);
        std::cout << json_file << std::endl;
    } else {
        Json::StreamWriterBuilder builder;
        const std::string json_file = Json::writeString (builder, root);
        std::cout << json_file << std::endl;
    }
    return EXIT_SUCCESS;

}