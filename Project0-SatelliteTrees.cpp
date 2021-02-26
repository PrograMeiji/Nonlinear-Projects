#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Satellite {

private:

    string name, country, who, classification, purpose, detail, orbit, dateLaunched, launchSite, launchVehicle, expectedLife;

    int noradNumber;
    float apogee, perigee, period;

public:

    Satellite();

    void Print();
    void writeFile(string);

    string getName() { return name; }
    string getCountry() { return country; }
    string getWho() { return who; }
    string getClassification() { return classification; }
    string getPurpose() { return purpose; }
    string getDetail() { return detail; }
    string getOrbit() { return orbit; }

    float getApogee() { return apogee; }
    float getPerigee() { return perigee; }
    float getPeriod() { return period; }

    string getDateLaunched() { return dateLaunched; }
    string getExpectedLife() { return expectedLife; }
    string getLaunchSite() { return launchSite; }
    string getLaunchVehicle() { return launchVehicle; }

    int getNoradNumber() { return noradNumber; }

    void setName(string nam) { name = nam; }
    void setCountry(string cou) { country = cou; }
    void setWho(string w) { who = w; }
    void setClassification(string cla) { classification = cla; }
    void setPurpose(string pur) { purpose = pur; }
    void setDetail(string det) { detail = det; }
    void setOrbit(string orb) { orbit = orb; }

    void setApogee(float apo) { apogee = apo; }
    void setPerigee(float peri) { perigee = peri; }
    void setPeriod(float perd) { period = perd; }

    void setDateLaunched(string datLau) { dateLaunched = datLau; }
    void setExpectedLife(string expLif) { expectedLife = expLif; }
    void setLaunchSite(string lauSit) { launchSite = lauSit; }
    void setLaunchVehicle(string lauVeh) { launchVehicle = lauVeh; }

    void setNoradNumber(int norNum) { noradNumber = norNum; }

};


void Satellite::Print() {

    cout << this->getName() << endl << this->getCountry() << endl << this->getWho() << endl << this->getClassification() << endl << this->getPurpose() <<
        endl << this->getDetail() << endl << this->getOrbit() << endl << this->getApogee() << endl << this->getPerigee() << endl << this->getPeriod() <<
        endl << this->getDateLaunched() << endl << this->getExpectedLife() << endl << this->getLaunchSite() << endl << this->getLaunchVehicle() << endl <<
        this->getNoradNumber() << endl << "----------------------------------------------------------------------" << endl;

}

Satellite::Satellite(void) {}

class SatelliteTree {

public:

    SatelliteTree* left, * right, * parent;
    Satellite satellite;

    SatelliteTree() {

        left = NULL;
        right = NULL;

    }

    SatelliteTree(Satellite sat) {

        left = NULL;
        right = NULL;
        satellite = sat;

    }

    void Insert(SatelliteTree*);
    void listAll();
    void writeFile(string);

    SatelliteTree* Search(string);
    SatelliteTree* Remove(string);

};

void SatelliteTree::Insert(SatelliteTree* satNode) {

    if (satNode == NULL) {

        return;

    }

    if (satNode->satellite.getName().compare(this->satellite.getName()) > 0) {

        if (this->right != NULL) {

            this->right->Insert(satNode);

        }

        else {

            this->right = satNode;
            this->right->parent = this;

        }
    }

    else

    {

        if (this->left != NULL) {

            this->left->Insert(satNode);

        }

        else {

            this->left = satNode;
            this->left->parent = this;

        }
    }
}

void Satellite::writeFile(string fileName) {

    std::ofstream writeFile;

    writeFile.open(fileName, std::ios_base::app);

    writeFile << this->getName() << endl;
    writeFile << this->getCountry() << endl;
    writeFile << this->getWho() << endl;
    writeFile << this->getClassification() << endl;
    writeFile << this->getPurpose() << endl;
    writeFile << this->getDetail() << endl;
    writeFile << this->getOrbit() << endl;
    writeFile << this->getApogee() << endl;
    writeFile << this->getPerigee() << endl;
    writeFile << this->getPeriod() << endl;
    writeFile << this->getDateLaunched() << endl;
    writeFile << this->getExpectedLife() << endl;
    writeFile << this->getLaunchSite() << endl;
    writeFile << this->getLaunchVehicle() << endl;
    writeFile << this->getNoradNumber() << endl;

}

SatelliteTree* SatelliteTree::Search(string name) {

    int result = name.compare(this->satellite.getName());

    if (result == 0) {

        return this;

    }

    else if (result > 0) {

        if (this->right != NULL) {

            return this->right->Search(name);

        }

        else {

            return NULL;

        }
    }

    else {

        if (this->left != NULL) {

            return this->left->Search(name);

        }

        else {

            return NULL;

        }
    }
}

SatelliteTree* Launch(SatelliteTree* satTree, SatelliteTree* satNode) {

    Satellite satellite;

    string name, country, who, classification, purpose, detail, orbit, dateLaunched, launchSite, launchVehicle, expectedLife, junk;

    int noradNumber;
    float apogee, perigee, period;

    cout << "Enter satellite name:" << endl;
    getline(cin, junk);
    getline(cin, name);
    satellite.setName(name);

    cout << "Enter satellite country:" << endl;
    getline(cin, country);
    satellite.setCountry(country);

    cout << "Enter satellite owner name:" << endl;
    getline(cin, who);
    satellite.setWho(who);

    cout << "Enter satellite classification:" << endl;
    getline(cin, classification);
    satellite.setClassification(classification);

    cout << "Enter satellite purpose:" << endl;
    getline(cin, purpose);
    satellite.setPurpose(purpose);

    cout << "Enter satellite details:" << endl;
    getline(cin, detail);
    satellite.setDetail(detail);

    cout << "Enter satellite orbit:" << endl;
    getline(cin, orbit);
    satellite.setOrbit(orbit);

    cout << "Enter satellite apogee:" << endl;
    cin >> apogee;
    satellite.setApogee(apogee);

    cout << "Enter satellite perigee:" << endl;
    cin >> perigee;
    satellite.setPerigee(perigee);

    cout << "Enter satellite period:" << endl;
    cin >> period;
    satellite.setPeriod(period);

    cout << "Enter date satellite was launched:" << endl;
    getline(cin, junk);
    getline(cin, dateLaunched);
    satellite.setDateLaunched(dateLaunched);

    cout << "Enter satellite expected life cycle:" << endl;
    getline(cin, expectedLife);
    satellite.setExpectedLife(expectedLife);

    cout << "Enter satellite launch site:" << endl;
    getline(cin, launchSite);
    satellite.setLaunchSite(launchSite);

    cout << "Enter satellite launch vehicle:" << endl;
    getline(cin, launchVehicle);
    satellite.setLaunchVehicle(launchVehicle);

    cout << "Enter satellite norad number:" << endl;
    cin >> noradNumber;
    satellite.setNoradNumber(noradNumber);

    if (satTree != NULL) {

        satNode = new SatelliteTree(satellite);
        satTree->right->Insert(satNode);

    }

    else {

        satTree = new SatelliteTree();
        satTree->right = new SatelliteTree(satellite);
        satTree->right->parent = satTree;

    }

    return satTree;

}

void SatelliteTree::writeFile(string fileName)
{

    if (this->left != NULL) {

        this->left->writeFile(fileName);

    }

    this->satellite.writeFile(fileName);

    if (this->right != NULL) {

        this->right->writeFile(fileName);

    }
}

SatelliteTree* SatelliteTree::Remove(string name) {

    SatelliteTree* satNode = this->Search(name);

    if (satNode == NULL) {

        return NULL;

    }

    SatelliteTree* parent = satNode->parent;

    satNode->parent = NULL;

    if (parent->right == satNode) {

        parent->right = NULL;

        if (satNode->right != NULL) {

            parent->right = satNode->right;
            parent->right->Insert(satNode->left);
            parent->right->parent = parent;

        }

        else if (satNode->left != NULL) {

            parent->right = satNode->left;
            parent->right->Insert(satNode->right);
            parent->right->parent = parent;

        }
    }

    else {

        parent->left = NULL;

        if (satNode->right != NULL) {

            parent->left = satNode->right;
            parent->left->Insert(satNode->left);
            parent->left->parent = parent;

        }

        else if (satNode->left != NULL) {

            parent->left = satNode->left;
            parent->left->Insert(satNode->right);
            parent->left->parent = parent;

        }
    }

    satNode->right = NULL;
    satNode->left = NULL;
    return satNode;

}

void SatelliteTree::listAll() {

    if (this->left != NULL) {

        this->left->listAll();

    }

    this->satellite.Print();

    if (this->right != NULL) {

        this->right->listAll();

    }
}

SatelliteTree* readFile(string fileName, SatelliteTree* satTree, SatelliteTree* satNode) {

    Satellite satellite;

    ifstream inFile;
    string name, country, who, classification, purpose, detail, orbit, dateLaunched, launchSite, launchVehicle, expectedLife, junk;

    int noradNumber;
    float apogee, perigee, period;

    inFile.open(fileName);

    if (inFile.is_open()) {

        while (inFile.good()) {

            getline(inFile, name);

            if (inFile.bad() || inFile.eof()) {

                inFile.close();
                break;

            }

            getline(inFile, country);
            getline(inFile, who);
            getline(inFile, classification);
            getline(inFile, purpose);
            getline(inFile, detail);
            getline(inFile, orbit);

            inFile >> apogee >> perigee >> period;

            getline(inFile, junk);  // move past the newline after period
            getline(inFile, dateLaunched);
            getline(inFile, expectedLife);  // floating Point or blank line. 
            getline(inFile, launchSite);
            getline(inFile, launchVehicle);

            inFile >> noradNumber;

            getline(inFile, junk); //move past the newline after the norad number

            satellite.setName(name);
            satellite.setCountry(country);
            satellite.setWho(who);
            satellite.setClassification(classification);
            satellite.setPurpose(purpose);
            satellite.setDetail(detail);
            satellite.setOrbit(orbit);
            satellite.setApogee(apogee);
            satellite.setPerigee(perigee);
            satellite.setPeriod(period);
            satellite.setDateLaunched(dateLaunched);
            satellite.setExpectedLife(expectedLife);
            satellite.setLaunchSite(launchSite);
            satellite.setLaunchVehicle(launchVehicle);
            satellite.setNoradNumber(noradNumber);

            if (satTree != NULL) {

                satNode = new SatelliteTree(satellite);
                satTree->right->Insert(satNode);

            }
            else {

                satTree = new SatelliteTree();
                satTree->right = new SatelliteTree(satellite);
                satTree->right->parent = satTree;

            }
        }

    }

    else {

        cerr << "Couldn't open file for reading\n";

    }

    return satTree;
}

int main() {

    Satellite satellite;
    string file1 = "inorbit.txt";
    string file2 = "deorbit.txt";
    SatelliteTree* inorbit = NULL;
    SatelliteTree* deorbit = NULL;
    SatelliteTree* satNode{};
    ofstream ofs;

    for (;;) {

        char input;
        string satName, junk;

        cout << "Enter an operation: " << endl;
        cin >> input;

        input = toupper(input);

        switch (input) {

        case 'Q':

            return EXIT_SUCCESS;

            break;

        case 'L':

            inorbit = Launch(inorbit, satNode);

            break;

        case 'F':

            cout << "Enter the satellite's name you want to find: " << endl;

            cin >> satName;

            if (inorbit == NULL || inorbit->right == NULL) {

                cout << "No satellites found in orbit." << endl;

            }

            satNode = inorbit->right->Search(satName);

            if (satNode != NULL) {

                satNode->satellite.Print();

            }
            else if (satNode == NULL) {

                if (deorbit == NULL || deorbit->right == NULL) {

                    cout << "There are no satellites grounded." << endl;

                }

                satNode = deorbit->right->Search(satName);
                satNode->satellite.Print();

                cout << "The satellite is no longer in orbit." << endl;

            }

            else {

                cout << "Entered satellite cannot be found." << endl;

            }

            break;

        case 'D':

            cout << "Enter the satellite's name to deorbit: " << endl;

            getline(cin, junk);
            getline(cin, satName);

            if (inorbit == NULL || inorbit->right == NULL) {

                cout << "There are no satellites in orbit." << endl;

            }

            satNode = inorbit->right->Remove(satName);

            if (satNode == NULL) {

                cout << "No matching satellite was found." << endl;

            }

            else {

                if (deorbit != NULL && deorbit->right != NULL) {

                    deorbit->right->Insert(satNode);

                }

                else {

                    deorbit = new SatelliteTree();
                    deorbit->right = satNode;
                    deorbit->right->parent = deorbit;

                }

                cout << "Entered satellite has been taken out of orbit." << endl;

            }

            break;

        case 'A':

            if (inorbit != NULL && inorbit->right != NULL) {

                cout << "In orbit satellites: " << endl << "----------------------------------------------------------------------------------------------" << endl;
                inorbit->right->listAll();

            }

            else {

                cout << "No satellites in orbit." << endl;
            }

            if (deorbit != NULL && deorbit->right != NULL) {

                cout << "Out of orbit satellites: " << endl << "----------------------------------------------------------------------------------------------" << endl;
                deorbit->right->listAll();

            }

            else {

                cout << endl << "No out of orbit satellites." << endl;

            }

            break;

        case 'S':

            ofs.open(file1, std::ofstream::out | std::ofstream::trunc);
            ofs.close();
            ofs.open(file2, std::ofstream::out | std::ofstream::trunc);
            ofs.close();

            if (inorbit != NULL && inorbit->right != NULL) {

                inorbit->right->writeFile(file1);

            }

            else {

                cout << "No satellites in orbit." << endl;

            }

            if (deorbit != NULL && deorbit->right != NULL) {

                deorbit->right->writeFile(file2);

            }

            else {

                cout << endl << "No satellites grounded." << endl;

            }

            break;

        case 'R':

            inorbit = NULL;
            deorbit = NULL;
            inorbit = readFile(file1, inorbit, satNode);
            deorbit = readFile(file2, deorbit, satNode);

            break;

        default:

            cout << "Entered operation is invalid. " << endl;

        }
    }

    return EXIT_SUCCESS;

}

