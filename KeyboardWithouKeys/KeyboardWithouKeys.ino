uint8_t isSecondElapsed = 0;

int main(void)
{
    while (true)
    {
        delay(100);
        isSecondElapsed = 1;
    }
}

bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo, uint8_t* const ReportID, const uint8_t ReportType, void* ReportData, uint16_t const ReportSize)
{
    USB_KeyboardReport_Data_t* KeyboardReport = (USB_KeyboardReport_Data_t*)ReportData;
    if(isSecondElapsed)
    {
        KeyboardReport->KeyCode[0] = HID_KEYBOARD_SC_X;
        isSecondElapsed=0;
    }
    *ReportSize = sizeof(USB_KeyboardReport_Data_t);
    return false;
} 
