#include "pycelex5.h"

using std::cout;
using std::endl;

PyCeleX5::PyCeleX5(bool debug)
{
    this->m_pCeleX5 = new CeleX5();
    this->m_bDebug = debug;
    cout << "PyCeleX5.PyCeleX5(): " << (debug ? "in debug mode" : "") << endl;
}

PyCeleX5::~PyCeleX5()
{
    delete this->m_pCeleX5;
    cout << "PyCeleX5.~PyCeleX5()" << endl;
}

// 2.3.1 openSensor
bool PyCeleX5::openSensor(CeleX5::DeviceType type)
{
    bool result = m_pCeleX5->openSensor(type);
    if (this->m_bDebug)
    {
        cout << "PyCeleX5.openSensor(): open sensor " << (result ? "successful" : "failed") << endl;
    }
    return result;
}

// 2.3.2 isSensorReady
bool PyCeleX5::isSensorReady()
{
    bool result = this->m_pCeleX5->isSensorReady();
    if (this->m_bDebug)
    {
        cout << "PyCeleX5.isSensorReady(): sensor " << (result ? "is" : "is not") << " ready" << endl;
    }
    return result;
}

// 2.3.3 getCeleXRawData

// 2.3.4 setFpnFile
bool PyCeleX5::setFpnFile(const std::string &fpnFile)
{
    bool result = this->m_pCeleX5->setFpnFile(fpnFile);
    if (this->m_bDebug)
    {
        cout << "PyCeleX5.setFpnFile(): " << fpnFile << endl;
        cout << "PyCeleX5.setFpnFile(): set FPN file " << (result ? "successful" : "failed") << endl;
    }
    return result;
}

// 2.3.5 generateFPN
void PyCeleX5::generateFpn(const std::string &fpnFile)
{
    this->m_pCeleX5->generateFPN(fpnFile);
    if (this->m_bDebug)
    {
        cout << "PyCeleX5.generateFpn(): " << fpnFile << endl;
    }
}

// 2.3.6 setSensorFixedMode
void PyCeleX5::setSensorFixedMode(CeleX5::CeleX5Mode mode)
{
    this->m_pCeleX5->setSensorFixedMode(mode);
    if (this->m_bDebug)
    {
        cout << "PyCeleX5.setSensorFixedMode(): called" << endl;
    }
}

// 2.3.7 getSensorFixedMode
CeleX5::CeleX5Mode PyCeleX5::getSensorFixedMode()
{
    CeleX5::CeleX5Mode result = this->m_pCeleX5->getSensorFixedMode();
    if (this->m_bDebug)
    {
        cout << "PyCeleX5.getSensorFixedMode(): called" << endl;
    }
    return result;
}
