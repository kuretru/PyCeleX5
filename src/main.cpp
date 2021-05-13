#include <pybind11/pybind11.h>
#include "../include/celex5/celex5.h"
#include "pycelex5.h"

namespace py = pybind11;

PYBIND11_MODULE(PyCeleX5, m)
{

    m.doc() = "CelePixel CeleX5-MIPI C++ Wrapper for Python 3";
    m.attr("WIDTH") = PyCeleX5::sm_uiWidth;
    m.attr("HEIGHT") = PyCeleX5::sm_uiHeight;
    m.attr("RESOLUTION") = PyCeleX5::sm_uiResolution;

    // py::class_<CeleX5> celex5(m, "CeleX5");

    py::enum_<CeleX5::DeviceType>(m, "DeviceType")
        .value("Unknown_Devive", CeleX5::DeviceType::Unknown_Devive)
        .value("CeleX5_MIPI", CeleX5::DeviceType::CeleX5_MIPI)
        .value("CeleX5_OpalKelly", CeleX5::DeviceType::CeleX5_OpalKelly)
        .export_values();

    py::enum_<CeleX5::CeleX5Mode>(m, "Celex5Mode")
        .value("Unknown_Mode", CeleX5::CeleX5Mode::Unknown_Mode)
        .value("Event_Off_Pixel_Timestamp_Mode", CeleX5::CeleX5Mode::Event_Off_Pixel_Timestamp_Mode)
        .value("Event_In_Pixel_Timestamp_Mode", CeleX5::CeleX5Mode::Event_In_Pixel_Timestamp_Mode)
        .value("Event_Intensity_Mode", CeleX5::CeleX5Mode::Event_Intensity_Mode)
        .value("Full_Picture_Mode", CeleX5::CeleX5Mode::Full_Picture_Mode)
        .value("Optical_Flow_Mode", CeleX5::CeleX5Mode::Optical_Flow_Mode)
        .value("Optical_Flow_FPN_Mode", CeleX5::CeleX5Mode::Optical_Flow_FPN_Mode)
        .value("Multi_Read_Optical_Flow_Mode", CeleX5::CeleX5Mode::Multi_Read_Optical_Flow_Mode)
        .export_values();

    py::enum_<CeleX5::EventPicType>(m, "EventPicType")
        .value("EventBinaryPic", CeleX5::EventPicType::EventBinaryPic)
        .value("EventAccumulatedPic", CeleX5::EventPicType::EventAccumulatedPic)
        .value("EventGrayPic", CeleX5::EventPicType::EventGrayPic)
        .value("EventCountPic", CeleX5::EventPicType::EventCountPic)
        .value("EventDenoisedBinaryPic", CeleX5::EventPicType::EventDenoisedBinaryPic)
        .value("EventSuperimposedPic", CeleX5::EventPicType::EventSuperimposedPic)
        .value("EventDenoisedCountPic", CeleX5::EventPicType::EventDenoisedCountPic)
        .value("EventCountDensityPic", CeleX5::EventPicType::EventCountDensityPic)
        .value("EventInPixelTimestampPic", CeleX5::EventPicType::EventInPixelTimestampPic)
        .export_values();

    py::enum_<CeleX5::OpticalFlowPicType>(m, "OpticalFlowPicType")
        .value("OpticalFlowPic", CeleX5::OpticalFlowPicType::OpticalFlowPic)
        .value("OpticalFlowSpeedPic", CeleX5::OpticalFlowPicType::OpticalFlowSpeedPic)
        .value("OpticalFlowDirectionPic", CeleX5::OpticalFlowPicType::OpticalFlowDirectionPic)
        .export_values();

    py::class_<PyCeleX5>(m, "PyCeleX5")
        .def(py::init<bool>(), py::arg("debug") = true)
        .def("openSensor", &PyCeleX5::openSensor, "bool openSensor(DeviceType type)", py::arg("type") = CeleX5::DeviceType::CeleX5_MIPI)
        .def("isSensorReady", &PyCeleX5::isSensorReady, "bool isSensorReady()")
        .def("setFpnFile", &PyCeleX5::setFpnFile, "bool setFpnFile(string fpnFile)", py::arg("fpnFile"))
        .def("generateFpn", &PyCeleX5::generateFpn, "void generateFpn(string fpnFile)", py::arg("fpnFile"))
        .def("setSensorFixedMode", &PyCeleX5::setSensorFixedMode, "void setSensorFixedMode(CeleX5Mode mode)", py::arg("mode"))
        .def("getSensorFixedMode", &PyCeleX5::getSensorFixedMode, "CeleX5Mode getSensorFixedMode()")
        .def("getFullPicBuffer", &PyCeleX5::getFullPicBuffer, "uint8_t[] getFullPicBuffer()")
        .def("getEventPicBuffer", &PyCeleX5::getEventPicBuffer, "uint8_t[] getFullPicBuffer(EventPicType type)", py::arg("type") = CeleX5::EventPicType::EventBinaryPic)
        .def("getOpticalFlowPicBuffer", &PyCeleX5::getOpticalFlowPicBuffer, "uint8_t[] getOpticalFlowPicBuffer(OpticalFlowPicType type)", py::arg("type") = CeleX5::OpticalFlowPicType::OpticalFlowPic)
        .def("getFullPicFrameTime", &PyCeleX5::getFullPicFrameTime, "uint32_t getFullPicFrameTime()")
        .def("setEventFrameTime", &PyCeleX5::setEventFrameTime, "void setEventFrameTime(uint32_t microsecond)", py::arg("microsecond"))
        .def("getEventFrameTime", &PyCeleX5::getEventFrameTime, "uint32_t getEventFrameTime()")
        .def("setOpticalFlowFrameTime", &PyCeleX5::setOpticalFlowFrameTime, "void setOpticalFlowFrameTime(uint32_t millisecond)", py::arg("millisecond"))
        .def("getOpticalFlowFrameTime", &PyCeleX5::getOpticalFlowFrameTime, "uint32_t getOpticalFlowFrameTime()")
        .def("setSensorLoopMode", &PyCeleX5::setSensorLoopMode, "void setSensorLoopMode(CeleX5Mode mode, int loopNum)", py::arg("mode"), py::arg("loopNum"))
        .def("getSensorLoopMode", &PyCeleX5::getSensorLoopMode, "CeleX5Mode getSensorLoopMode(int loopNum)", py::arg("loopNum"))
        .def("setLoopModeEnabled", &PyCeleX5::setLoopModeEnabled, "void setLoopModeEnabled(bool enable)", py::arg("enable"))
        .def("isLoopModeEnabled", &PyCeleX5::isLoopModeEnabled, "bool isLoopModeEnabled()")
        .def("setEventDuration", &PyCeleX5::setEventDuration, "void setEventDuration(uint32_t value)", py::arg("value"))
        .def("setPictureNumber", &PyCeleX5::setPictureNumber, "void setPictureNumber(uint32_t num, CeleX5::CeleX5Mode mode)", py::arg("num"), py::arg("mode"))
        .def("setThreshold", &PyCeleX5::setThreshold, "void setThreshold(uint32_t value)", py::arg("value"))
        .def("getThreshold", &PyCeleX5::getThreshold, "uint32_t getThreshold()")
        .def("setBrightness", &PyCeleX5::setBrightness, "void setBrightness(uint32_t value)", py::arg("value"))
        .def("getBrightness", &PyCeleX5::getBrightness, "uint32_t getBrightness()")
        .def("setContrast", &PyCeleX5::setContrast, "void setContrast(uint32_t value)", py::arg("value"))
        .def("getContrast", &PyCeleX5::getContrast, "uint32_t getContrast()");
}
