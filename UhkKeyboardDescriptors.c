const USB_Descriptor_Device_t PROGMEM DeviceDescriptor =
{
    .Header                 = {.Size = sizeof(USB_Descriptor_Device_t), .Type = DTYPE_Device},

    .USBSpecification       = VERSION_BCD(01.10),
    .Class                  = USB_CSCP_NoDeviceClass,
    .SubClass               = USB_CSCP_NoDeviceSubclass,
    .Protocol               = USB_CSCP_NoDeviceProtocol,

    .Endpoint0Size          = FIXED_CONTROL_ENDPOINT_SIZE,

    .VendorID               = VID,
    .ProductID              = PID_KEYBOARD_6KRO,
    .ReleaseNumber          = VERSION_BCD(00.01),

    .ManufacturerStrIndex   = STRING_ID_Manufacturer,
    .ProductStrIndex        = STRING_ID_Product,
    .SerialNumStrIndex      = NO_DESCRIPTOR,

    .NumberOfConfigurations = FIXED_NUM_CONFIGURATIONS
};

typedef struct
{
    USB_Descriptor_Configuration_Header_t Config;

    // Generic HID Interface
    USB_Descriptor_Interface_t            HID1_GenericHIDInterface;
    USB_HID_Descriptor_HID_t              HID1_GenericHID;
    USB_Descriptor_Endpoint_t             HID1_ReportINEndpoint;

    // Keyboard HID Interface
    USB_Descriptor_Interface_t            HID2_KeyboardInterface;
    USB_HID_Descriptor_HID_t              HID2_KeyboardHID;
    USB_Descriptor_Endpoint_t             HID2_ReportINEndpoint;

    // Mouse HID Interface
    USB_Descriptor_Interface_t            HID3_MouseInterface;
    USB_HID_Descriptor_HID_t              HID3_MouseHID;
    USB_Descriptor_Endpoint_t             HID3_ReportINEndpoint;
} Keyboard_USB_Descriptor_Configuration_t;

const Keyboard_USB_Descriptor_Configuration_t PROGMEM ConfigurationDescriptor =
{
    .Config =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Configuration_Header_t), .Type = DTYPE_Configuration},

            .TotalConfigurationSize = sizeof(Keyboard_USB_Descriptor_Configuration_t),
            .TotalInterfaces        = 3,

            .ConfigurationNumber    = 1,
            .ConfigurationStrIndex  = NO_DESCRIPTOR,

            .ConfigAttributes       = (USB_CONFIG_ATTR_RESERVED | USB_CONFIG_ATTR_SELFPOWERED),

            .MaxPowerConsumption    = USB_CONFIG_POWER_MA(100)
        },

    .HID1_GenericHIDInterface =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},

            .InterfaceNumber        = INTERFACE_ID_GenericHID,
            .AlternateSetting       = 0x00,

            .TotalEndpoints         = 1,

            .Class                  = HID_CSCP_HIDClass,
            .SubClass               = HID_CSCP_NonBootSubclass,
            .Protocol               = HID_CSCP_NonBootProtocol,

            .InterfaceStrIndex      = NO_DESCRIPTOR
        },

    .HID1_GenericHID =
        {
            .Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},

            .HIDSpec                = VERSION_BCD(01.11),
            .CountryCode            = 0x00,
            .TotalReportDescriptors = 1,
            .HIDReportType          = HID_DTYPE_Report,
            .HIDReportLength        = sizeof(GenericReport)
        },

    .HID1_ReportINEndpoint =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

            .EndpointAddress        = GENERIC_IN_EPADDR,
            .Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
            .EndpointSize           = GENERIC_EPSIZE,
            .PollingIntervalMS      = 0x05
        },

    .HID2_KeyboardInterface =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},

            .InterfaceNumber        = INTERFACE_ID_Keyboard,
            .AlternateSetting       = 0x00,

            .TotalEndpoints         = 1,

            .Class                  = HID_CSCP_HIDClass,
            .SubClass               = HID_CSCP_BootSubclass,
            .Protocol               = HID_CSCP_KeyboardBootProtocol,

            .InterfaceStrIndex      = NO_DESCRIPTOR
        },

    .HID2_KeyboardHID =
        {
            .Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},

            .HIDSpec                = VERSION_BCD(01.11),
            .CountryCode            = 0x00,
            .TotalReportDescriptors = 1,
            .HIDReportType          = HID_DTYPE_Report,
            .HIDReportLength        = sizeof(KeyboardReport)
        },

    .HID2_ReportINEndpoint =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

            .EndpointAddress        = KEYBOARD_IN_EPADDR,
            .Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
            .EndpointSize           = HID_EPSIZE,
            .PollingIntervalMS      = 0x05
        },

    .HID3_MouseInterface =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},

            .InterfaceNumber        = INTERFACE_ID_Mouse,
            .AlternateSetting       = 0x00,

            .TotalEndpoints         = 1,

            .Class                  = HID_CSCP_HIDClass,
            .SubClass               = HID_CSCP_BootSubclass,
            .Protocol               = HID_CSCP_MouseBootProtocol,

            .InterfaceStrIndex      = NO_DESCRIPTOR
        },

    .HID3_MouseHID =
        {
            .Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},

            .HIDSpec                = VERSION_BCD(01.11),
            .CountryCode            = 0x00,
            .TotalReportDescriptors = 1,
            .HIDReportType          = HID_DTYPE_Report,
            .HIDReportLength        = sizeof(MouseReport)
        },

    .HID3_ReportINEndpoint =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

            .EndpointAddress        = MOUSE_IN_EPADDR,
            .Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
            .EndpointSize           = HID_EPSIZE,
            .PollingIntervalMS      = 0x05
        }
};