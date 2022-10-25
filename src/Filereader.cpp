std::string Filereader::removeComma(std::string in){
    std::string out = "";
    for(unsigned long int i = 0; i < in.size(); i++){
        if(in[i]!=',') out+=in[i];
        else out+=' ';
    }
    return(out);
}

map<std::string,UC> Filereader::readUcs() {
    map<std::string,UC> out;
    std::string line;
    std::ifstream ifs("../classes_per_uc.csv");
    std::getline(ifs,line);
    while(std::getline(ifs,line)){
        line = removeComma(line);
        std::istringstream iss(line);
        std::string ucName, className;
        iss >> ucName >> className;
        if(out.find(ucName)==out.end()) out.insert(pair<std::string ,UC>(ucName,UC(ucName)));
        out.at(ucName).classes.insert(pair<std::string,Class_Hour>(className,Class_Hour(className)));
    }
    return(out);
}

map<std::string, UC> Filereader::readClasses(map<std::string, UC> in) {
    map<std::string,UC> out = in;
    std::string line;
    std::ifstream ifs("../classes.csv");
    std::getline(ifs,line);
    while(std::getline(ifs,line)){
        line = removeComma(line);
        std::istringstream iss(line);
        std::string classCode, ucCode, day, classType;
        float startHour, duration;
        iss >> classCode >> ucCode >> day >> startHour >> duration >> classType;
        if(out.find(ucCode)!=out.end() && out.at(ucCode).classes.find(classCode)!=out.at(ucCode).classes.end()) out.at(ucCode).classes.at(classCode).lectures.push_back(Lecture(classCode,day,startHour,duration,classType));
    }
    return out;
}
