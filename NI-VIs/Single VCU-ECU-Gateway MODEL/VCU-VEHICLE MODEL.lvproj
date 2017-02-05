<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="15008000">
	<Property Name="NI.LV.ExampleFinder" Type="Str">&lt;?xml version="1.0" encoding="UTF-8"?&gt;
&lt;nidna:ExampleProgram 
    xmlns:nidna="http://www.ni.com/Schemas/DNA/1.0" 
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" 
    xsi:schemaLocation="http://www.ni.com/Schemas/DNA/1.0 ..\DNA\1.0\NiExampleProgram.xsd" 
    SchemaVersion="1.0" 
    ContentType="EXAMPLE" 
&lt;Title&gt;
	&lt;Text Locale="US"&gt;CAN Basic.lvproj&lt;/Text&gt;
&lt;/Title&gt;
&lt;Description&gt;
	&lt;Text Locale="US"&gt;This example demonstrates basic communication on the CAN bus. The example runs standalone (without a host VI).

It reads CAN frames on CAN 0 and displays a count along with the most recent frame. It transmits a CAN frame on CAN 1 each time you select the Transmit button. You can use the example simply by connecting a CAN cable (powered) between CAN 0 and CAN 1. To use the example with an external CAN device (such as an ECU), connect the device to CAN 0, then change the CAN Output node from CAN 1 to CAN 0. This enables you to interactively transmit and receive CAN frames with the external device.

This example assumes the following configuration for CAN 0 and CAN 1: Auto Start = True, Listen Only = False, Input Timeout = 10000ms, Output Timeout = 10000ms. The CAN Input and CAN Output nodes are configured to use Cluster for the CAN frame. For more information on configuration, refer to the Help for the NI 9852/9853 CAN modules.

If you change this example such that the loops exit normally (such as a stop button), you must add the CAN Stop method to stop CAN communication before the VI stops execution. Only the LabVIEW abort button stops CAN communication when running standalone (no host VI).&lt;/Text&gt;
&lt;/Description&gt;
&lt;Keywords&gt;
	&lt;Item&gt;cRIO&lt;/Item&gt;
	&lt;Item&gt;FPGA&lt;/Item&gt;
	&lt;Item&gt;CAN&lt;/Item&gt;
	&lt;Item&gt;basic&lt;/Item&gt;
&lt;/Keywords&gt;
&lt;Navigation&gt;
	&lt;Item&gt;7424&lt;/Item&gt;
	&lt;Item&gt;6973&lt;/Item&gt;
	&lt;Item&gt;7693&lt;/Item&gt;
&lt;/Navigation&gt;
&lt;FileType&gt;LV Project&lt;/FileType&gt;
&lt;Metadata&gt;
&lt;Item Name="RTSupport"&gt;LV Project&lt;/Item&gt;
&lt;/Metadata&gt;
&lt;ProgrammingLanguages&gt;
&lt;Item&gt;LabVIEW&lt;/Item&gt;
&lt;/ProgrammingLanguages&gt;
&lt;RequiredSoftware&gt;
&lt;NiSoftware MinVersion="8.0"&gt;LabVIEW&lt;/NiSoftware&gt; 
&lt;/RequiredSoftware&gt;
&lt;RequiredCANHardware&gt;
&lt;Device&gt;
&lt;Model&gt;71F3&lt;/Model&gt;
&lt;Model&gt;714F&lt;/Model&gt;
&lt;/Device&gt;
&lt;/RequiredCANHardware&gt;
</Property>
	<Property Name="NI.Project.Description" Type="Str">This example demonstrates basic communication on the CAN bus. The example runs standalone (without a host VI).

It reads CAN frames on CAN 0 and displays a count along with the most recent frame. It transmits a CAN frame on CAN 1 each time you select the Transmit button. You can use the example simply by connecting a CAN cable (powered) between CAN 0 and CAN 1. To use the example with an external CAN device (such as an ECU), connect the device to CAN 0, then change the CAN Output node from CAN 1 to CAN 0. This enables you to interactively transmit and receive CAN frames with the external device.

This example assumes the following configuration for CAN 0 and CAN 1: Auto Start = True, Listen Only = False, Input Timeout = 10000ms, Output Timeout = 10000ms. The CAN Input and CAN Output nodes are configured to use Cluster for the CAN frame. For more information on configuration, refer to the Help for the NI 9852/9853 CAN modules.

If you change this example such that the loops exit normally (such as a stop button), you must add the CAN Stop method to stop CAN communication before the VI stops execution. Only the LabVIEW abort button stops CAN communication when running standalone (no host VI).</Property>
	<Item Name="My Computer" Type="My Computer">
		<Property Name="CCSymbols" Type="Str">OS_hidden,Win;CPU_hidden,x86;OS,Win;CPU,x86;</Property>
		<Property Name="NI.SortType" Type="Int">3</Property>
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">3363</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Read from Network.vi" Type="VI" URL="../Read from Network.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="usiSequenceRepresentation.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/usiSequenceRepresentation.ctl"/>
				<Item Name="usiOverwriteOptions.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/usiOverwriteOptions.ctl"/>
				<Item Name="_stringsToBeTranslated.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_stringsToBeTranslated.ctl"/>
				<Item Name="_L_localizedStrings.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_L_localizedStrings.vi"/>
				<Item Name="_openStorageWithRootAutoDetect.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_openStorageWithRootAutoDetect.vi"/>
				<Item Name="_openFunction.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_openFunction.ctl"/>
				<Item Name="_openStorageWithRootNoPluginCheck.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_openStorageWithRootNoPluginCheck.vi"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="_openWithRoot.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_openWithRoot.vi"/>
				<Item Name="_saveProperty.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_saveProperty.vi"/>
				<Item Name="__savePropFloat64.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropFloat64.vi"/>
				<Item Name="__savePropErrFilter.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropErrFilter.vi"/>
				<Item Name="__setErrSource.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__setErrSource.vi"/>
				<Item Name="_L_stringTable.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_L_stringTable.vi"/>
				<Item Name="__savePropInt16.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropInt16.vi"/>
				<Item Name="__savePropRef.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropRef.vi"/>
				<Item Name="__savePropRefList.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropRefList.vi"/>
				<Item Name="__savePropEnum.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropEnum.vi"/>
				<Item Name="__savePropInt32.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropInt32.vi"/>
				<Item Name="__savePropFloat32.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropFloat32.vi"/>
				<Item Name="__savePropUInt8.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropUInt8.vi"/>
				<Item Name="__savePropTime.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropTime.vi"/>
				<Item Name="__convertUtcTime.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__convertUtcTime.vi"/>
				<Item Name="__savePropString.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropString.vi"/>
				<Item Name="_createObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_createObject.vi"/>
				<Item Name="__linkRefnumDefinitionObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__linkRefnumDefinitionObject.vi"/>
				<Item Name="__queryObjects.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__queryObjects.vi"/>
				<Item Name="_openDataStorage.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_openDataStorage.vi"/>
				<Item Name="__createXmlString.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__createXmlString.vi"/>
				<Item Name="_findOpenStorage.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_findOpenStorage.vi"/>
				<Item Name="ParseXMLParams.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/ParseXMLParams.vi"/>
				<Item Name="_L_NodeNames.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_L_NodeNames.vi"/>
				<Item Name="List DataPlugins.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/utility/List DataPlugins.vi"/>
				<Item Name="usiPluginInformation.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/utility/usiPluginInformation.ctl"/>
				<Item Name="_sortStorageFormat.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/utility/_sortStorageFormat.vi"/>
				<Item Name="_getPluginListFromUsiEx.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_getPluginListFromUsiEx.vi"/>
				<Item Name="_getPluginListFromUsi.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_getPluginListFromUsi.vi"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
				<Item Name="Get File Extension.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/libraryn.llb/Get File Extension.vi"/>
				<Item Name="ErrorOut.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/xStorage/xStorageSupp/ErrorOut.vi"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="_createOrGetExplicitChildObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_createOrGetExplicitChildObject.vi"/>
				<Item Name="_createExplicitChildObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_createExplicitChildObject.vi"/>
				<Item Name="_loadProperty.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_loadProperty.vi"/>
				<Item Name="__loadPropFloat64.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropFloat64.vi"/>
				<Item Name="__loadPropString.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropString.vi"/>
				<Item Name="__loadPropRef.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropRef.vi"/>
				<Item Name="usiDataType.ctl" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_EditUserDefinedProperties/usiDataType.ctl"/>
				<Item Name="__loadPropErrFilter.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropErrFilter.vi"/>
				<Item Name="__loadPropRefList.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropRefList.vi"/>
				<Item Name="__loadPropInt16.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropInt16.vi"/>
				<Item Name="__loadPropEnum.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropEnum.vi"/>
				<Item Name="_getPropertyType.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_getPropertyType.vi"/>
				<Item Name="__getPropertyTypeObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/__getPropertyTypeObject.vi"/>
				<Item Name="usiPropDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/usiPropDef.ctl"/>
				<Item Name="specialProperties.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/specialProperties.ctl"/>
				<Item Name="_loadPropertyDefinitions.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_loadPropertyDefinitions.vi"/>
				<Item Name="__getPropertyTypeStorage.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/__getPropertyTypeStorage.vi"/>
				<Item Name="Get Property Type.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/Get Property Type.vi"/>
				<Item Name="_mapTdmObjectTypes.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_mapTdmObjectTypes.vi"/>
				<Item Name="_getPropDefByName.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_getPropDefByName.vi"/>
				<Item Name="_mapTdmPropertyNames.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_mapTdmPropertyNames.vi"/>
				<Item Name="_getObjDefByName.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_getObjDefByName.vi"/>
				<Item Name="dataModel.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/dataModel.ctl"/>
				<Item Name="usiTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/usiTypeDef.ctl"/>
				<Item Name="_TDM_DATA_MODEL.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_TDM_DATA_MODEL.vi"/>
				<Item Name="__loadPropFloat32.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropFloat32.vi"/>
				<Item Name="__loadPropUInt8.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropUInt8.vi"/>
				<Item Name="__loadPropTime.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropTime.vi"/>
				<Item Name="__loadPropInt32.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropInt32.vi"/>
				<Item Name="_createOrGetByNameExplicitChildObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_createOrGetByNameExplicitChildObject.vi"/>
				<Item Name="__saveStringChannel.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/__saveStringChannel.vi"/>
				<Item Name="usiValueFlags.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/usiValueFlags.ctl"/>
				<Item Name="Get Object Info.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/Get Object Info.vi"/>
				<Item Name="_isTdmDataStructure.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_isTdmDataStructure.vi"/>
				<Item Name="_loadObjectDefinitions.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_loadObjectDefinitions.vi"/>
				<Item Name="__linkRefnumDefinitionStorage.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__linkRefnumDefinitionStorage.vi"/>
				<Item Name="__closeStorageFromObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__closeStorageFromObject.vi"/>
				<Item Name="_closeDataStorage.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_closeDataStorage.vi"/>
				<Item Name="_commitTransaction.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_commitTransaction.vi"/>
				<Item Name="_commitStorage.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_commitStorage.vi"/>
				<Item Name="_commitObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_commitObject.vi"/>
			</Item>
			<Item Name="lvStorage.dll" Type="Document" URL="lvStorage.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
	<Item Name="RT CompactRIO Target" Type="RT CompactRIO">
		<Property Name="alias.name" Type="Str">RT CompactRIO Target</Property>
		<Property Name="alias.value" Type="Str">192.168.1.74</Property>
		<Property Name="CCSymbols" Type="Str">TARGET_TYPE,RT;OS,Linux;CPU,ARM;DeviceCode,7740;</Property>
		<Property Name="crio.ControllerPID" Type="Str">7740</Property>
		<Property Name="crio.family" Type="Str">900x</Property>
		<Property Name="host.ResponsivenessCheckEnabled" Type="Bool">true</Property>
		<Property Name="host.ResponsivenessCheckPingDelay" Type="UInt">5000</Property>
		<Property Name="host.ResponsivenessCheckPingTimeout" Type="UInt">1000</Property>
		<Property Name="host.TargetCPUID" Type="UInt">8</Property>
		<Property Name="host.TargetOSID" Type="UInt">8</Property>
		<Property Name="NI.SortType" Type="Int">3</Property>
		<Property Name="target.cleanupVisa" Type="Bool">false</Property>
		<Property Name="target.FPProtocolGlobals_ControlTimeLimit" Type="Int">300</Property>
		<Property Name="target.getDefault-&gt;WebServer.Port" Type="Int">80</Property>
		<Property Name="target.getDefault-&gt;WebServer.Timeout" Type="Int">60</Property>
		<Property Name="target.IOScan.Faults" Type="Str">1.0,0;</Property>
		<Property Name="target.IOScan.NetVarPeriod" Type="UInt">100</Property>
		<Property Name="target.IOScan.NetWatchdogEnabled" Type="Bool">false</Property>
		<Property Name="target.IOScan.Period" Type="UInt">3000</Property>
		<Property Name="target.IOScan.PowerupMode" Type="UInt">0</Property>
		<Property Name="target.IOScan.Priority" Type="UInt">0</Property>
		<Property Name="target.IOScan.ReportModeConflict" Type="Bool">false</Property>
		<Property Name="target.IOScan.StartEngineOnDeploy" Type="Bool">false</Property>
		<Property Name="target.IsRemotePanelSupported" Type="Bool">true</Property>
		<Property Name="target.RTCPULoadMonitoringEnabled" Type="Bool">true</Property>
		<Property Name="target.RTDebugWebServerHTTPPort" Type="Int">8001</Property>
		<Property Name="target.RTTarget.ApplicationPath" Type="Path">/c/ni-rt/startup/startup.rtexe</Property>
		<Property Name="target.RTTarget.EnableFileSharing" Type="Bool">true</Property>
		<Property Name="target.RTTarget.IPAccess" Type="Str">+*</Property>
		<Property Name="target.RTTarget.LaunchAppAtBoot" Type="Bool">false</Property>
		<Property Name="target.RTTarget.VIPath" Type="Path">/c/ni-rt/startup</Property>
		<Property Name="target.server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="target.server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="target.server.tcp.access" Type="Str">+*</Property>
		<Property Name="target.server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="target.server.tcp.paranoid" Type="Bool">true</Property>
		<Property Name="target.server.tcp.port" Type="Int">3363</Property>
		<Property Name="target.server.tcp.serviceName" Type="Str"></Property>
		<Property Name="target.server.tcp.serviceName.default" Type="Str">Main Application Instance/VI Server</Property>
		<Property Name="target.server.vi.access" Type="Str">+*</Property>
		<Property Name="target.server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="target.server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="target.WebServer.Config" Type="Str">Listen 8000

NI.ServerName default
DocumentRoot "$LVSERVER_DOCROOT"
TypesConfig "$LVSERVER_CONFIGROOT/mime.types"
DirectoryIndex index.htm
WorkerLimit 10
InactivityTimeout 60

LoadModulePath "$LVSERVER_MODULEPATHS"
LoadModule LVAuth lvauthmodule
LoadModule LVRFP lvrfpmodule

#
# Pipeline Definition
#

SetConnector netConnector

AddHandler LVAuth
AddHandler LVRFP

AddHandler fileHandler ""

AddOutputFilter chunkFilter


</Property>
		<Property Name="target.WebServer.Enabled" Type="Bool">false</Property>
		<Property Name="target.WebServer.LogEnabled" Type="Bool">false</Property>
		<Property Name="target.WebServer.LogPath" Type="Path">/c/ni-rt/system/www/www.log</Property>
		<Property Name="target.WebServer.Port" Type="Int">80</Property>
		<Property Name="target.WebServer.RootPath" Type="Path">/c/ni-rt/system/www</Property>
		<Property Name="target.WebServer.TcpAccess" Type="Str">C+*</Property>
		<Property Name="target.WebServer.Timeout" Type="Int">60</Property>
		<Property Name="target.WebServer.ViAccess" Type="Str">+*</Property>
		<Property Name="target.webservices.SecurityAPIKey" Type="Str">PqVr/ifkAQh+lVrdPIykXlFvg12GhhQFR8H9cUhphgg=:pTe9HRlQuMfJxAG6QCGq7UvoUpJzAzWGKy5SbZ+roSU=</Property>
		<Property Name="target.webservices.ValidTimestampWindow" Type="Int">15</Property>
		<Item Name="Chassis" Type="cRIO Chassis">
			<Property Name="crio.ProgrammingMode" Type="Str">fpga</Property>
			<Property Name="crio.ResourceID" Type="Str">RIO0</Property>
			<Property Name="crio.Type" Type="Str">cRIO-9063</Property>
			<Item Name="FPGA Target" Type="FPGA Target">
				<Property Name="AutoRun" Type="Bool">false</Property>
				<Property Name="configString.guid" Type="Str">{04E10E0D-C6CA-4C2E-ACDB-E090AA7DBF28}resource=/crio_Mod1/CAN0;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\RIO\nicrio_985x_controls.llb\CAN_IO_IONode Data Type.ctl{3E7C025C-2602-433B-A6B5-AF161FFB98E1}resource=/Scan Clock;0;ReadMethodType=bool{5F5116D2-4A6F-4EEA-A7F5-E0DD63C2404C}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{847971E5-33D5-4829-BA79-05359A6E8B21}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9853,cRIOModule.AutoStart0=true,cRIOModule.AutoStart1=true,cRIOModule.BaudRate0=21,cRIOModule.BaudRate1=21,cRIOModule.BitTiming0=7169,cRIOModule.BitTiming1=7169,cRIOModule.IDDisplay0=0,cRIOModule.IDDisplay1=0,cRIOModule.IDFormat0=0,cRIOModule.IDFormat1=0,cRIOModule.InoutFilter0=0,cRIOModule.InoutFilter1=0,cRIOModule.InputTimeout0=10000,cRIOModule.InputTimeout1=10000,cRIOModule.ListenOnly0=false,cRIOModule.ListenOnly1=false,cRIOModule.ModuleClock0=1,cRIOModule.ModuleClock1=255,cRIOModule.ModuleType0=3,cRIOModule.ModuleType1=3,cRIOModule.OutputTimeout0=10000,cRIOModule.OutputTimeout1=10000,cRIOModule.SelectedU32IDs0=,cRIOModule.SelectedU32IDs1=,cRIOModule.SJA1000Code0=0,cRIOModule.SJA1000Code1=0,cRIOModule.SJA1000FilteMask0=-1,cRIOModule.SJA1000FilteMask1=-1,cRIOModule.SJA1000FilterMode0=1,cRIOModule.SJA1000FilterMode1=1,cRIOModule.SpecifyBitTiming0=false,cRIOModule.SpecifyBitTiming1=false,cRIOModule.Termination0=0,cRIOModule.Termination1=0[crioConfig.End]{966F80AB-ED2D-49CE-999A-D496CDC49418}ArbitrationForOutputData=NeverArbitrate;NumberOfSyncRegistersForOutputData=1;NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA LED;0;ReadMethodType=bool;WriteMethodType=bool{9BD83521-8B19-4FFF-A1EE-2EBB561327EE}"ControlLogic=0;NumberOfElements=2047;Type=2;ReadArbs=Arbitrate if Multiple Requestors Only;ElementsPerRead=1;WriteArbs=Arbitrate if Multiple Requestors Only;ElementsPerWrite=1;Implementation=2;CAN1 - FIFO;DataType=1000800000000001000940070003553332000100000000000000000000;DisableOnOverflowUnderflow=FALSE"{B16E35CD-2A03-4B05-9280-0400110868B0}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{B896B164-FF59-4350-B595-B3396D0DA6BE}resource=/crio_Mod1/CAN1;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\RIO\nicrio_985x_controls.llb\CAN_IO_IONode Data Type.ctl{E3FAA6CD-DFAE-409F-8A1E-C322D14F7517}resource=/Chassis Temperature;0;ReadMethodType=i16{FA452095-4F07-4124-BDD4-27C24FD8F9CE}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolcRIO-9063/Clk40/falsefalseFPGA_EXECUTION_MODEFPGA_TARGETFPGA_TARGET_CLASSCRIO_9063FPGA_TARGET_FAMILYZYNQTARGET_TYPEFPGA/[rSeriesConfig.Begin][rSeriesConfig.End]</Property>
				<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;CAN1 - FIFO"ControlLogic=0;NumberOfElements=2047;Type=2;ReadArbs=Arbitrate if Multiple Requestors Only;ElementsPerRead=1;WriteArbs=Arbitrate if Multiple Requestors Only;ElementsPerWrite=1;Implementation=2;CAN1 - FIFO;DataType=1000800000000001000940070003553332000100000000000000000000;DisableOnOverflowUnderflow=FALSE"Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9063/Clk40/falsefalseFPGA_EXECUTION_MODEFPGA_TARGETFPGA_TARGET_CLASSCRIO_9063FPGA_TARGET_FAMILYZYNQTARGET_TYPEFPGA/[rSeriesConfig.Begin][rSeriesConfig.End]Mod1/CAN0resource=/crio_Mod1/CAN0;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\RIO\nicrio_985x_controls.llb\CAN_IO_IONode Data Type.ctlMod1/CAN1resource=/crio_Mod1/CAN1;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\RIO\nicrio_985x_controls.llb\CAN_IO_IONode Data Type.ctlMod1[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9853,cRIOModule.AutoStart0=true,cRIOModule.AutoStart1=true,cRIOModule.BaudRate0=21,cRIOModule.BaudRate1=21,cRIOModule.BitTiming0=7169,cRIOModule.BitTiming1=7169,cRIOModule.IDDisplay0=0,cRIOModule.IDDisplay1=0,cRIOModule.IDFormat0=0,cRIOModule.IDFormat1=0,cRIOModule.InoutFilter0=0,cRIOModule.InoutFilter1=0,cRIOModule.InputTimeout0=10000,cRIOModule.InputTimeout1=10000,cRIOModule.ListenOnly0=false,cRIOModule.ListenOnly1=false,cRIOModule.ModuleClock0=1,cRIOModule.ModuleClock1=255,cRIOModule.ModuleType0=3,cRIOModule.ModuleType1=3,cRIOModule.OutputTimeout0=10000,cRIOModule.OutputTimeout1=10000,cRIOModule.SelectedU32IDs0=,cRIOModule.SelectedU32IDs1=,cRIOModule.SJA1000Code0=0,cRIOModule.SJA1000Code1=0,cRIOModule.SJA1000FilteMask0=-1,cRIOModule.SJA1000FilteMask1=-1,cRIOModule.SJA1000FilterMode0=1,cRIOModule.SJA1000FilterMode1=1,cRIOModule.SpecifyBitTiming0=false,cRIOModule.SpecifyBitTiming1=false,cRIOModule.Termination0=0,cRIOModule.Termination1=0[crioConfig.End]Scan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolUSER FPGA LEDArbitrationForOutputData=NeverArbitrate;NumberOfSyncRegistersForOutputData=1;NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA LED;0;ReadMethodType=bool;WriteMethodType=bool</Property>
				<Property Name="NI.LV.FPGA.CompileConfigString" Type="Str">cRIO-9063/Clk40/falsefalseFPGA_EXECUTION_MODEFPGA_TARGETFPGA_TARGET_CLASSCRIO_9063FPGA_TARGET_FAMILYZYNQTARGET_TYPEFPGA</Property>
				<Property Name="NI.LV.FPGA.Version" Type="Int">6</Property>
				<Property Name="Resource Name" Type="Str">RIO0</Property>
				<Property Name="Target Class" Type="Str">cRIO-9063</Property>
				<Property Name="Top-Level Timing Source" Type="Str">40 MHz Onboard Clock</Property>
				<Property Name="Top-Level Timing Source Is Default" Type="Bool">true</Property>
				<Item Name="Chassis I/O" Type="Folder">
					<Item Name="Chassis Temperature" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/Chassis Temperature</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{E3FAA6CD-DFAE-409F-8A1E-C322D14F7517}</Property>
					</Item>
					<Item Name="Sleep" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/Sleep</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{5F5116D2-4A6F-4EEA-A7F5-E0DD63C2404C}</Property>
					</Item>
					<Item Name="System Reset" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/System Reset</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{FA452095-4F07-4124-BDD4-27C24FD8F9CE}</Property>
					</Item>
					<Item Name="USER FPGA LED" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="NumberOfSyncRegistersForOutputData">
   <Value>1</Value>
   </Attribute>
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/USER FPGA LED</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{966F80AB-ED2D-49CE-999A-D496CDC49418}</Property>
					</Item>
					<Item Name="Scan Clock" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/Scan Clock</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{3E7C025C-2602-433B-A6B5-AF161FFB98E1}</Property>
					</Item>
				</Item>
				<Item Name="Mod1" Type="Folder">
					<Item Name="Mod1/CAN0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/CAN0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{04E10E0D-C6CA-4C2E-ACDB-E090AA7DBF28}</Property>
					</Item>
					<Item Name="Mod1/CAN1" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/CAN1</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{B896B164-FF59-4350-B595-B3396D0DA6BE}</Property>
					</Item>
				</Item>
				<Item Name="40 MHz Onboard Clock" Type="FPGA Base Clock">
					<Property Name="FPGA.PersistentID" Type="Str">{B16E35CD-2A03-4B05-9280-0400110868B0}</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig" Type="Str">ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.Accuracy" Type="Dbl">100</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.ClockSignalName" Type="Str">Clk40</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.MaxDutyCycle" Type="Dbl">50</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.MaxFrequency" Type="Dbl">40000000</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.MinDutyCycle" Type="Dbl">50</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.MinFrequency" Type="Dbl">40000000</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.NominalFrequency" Type="Dbl">40000000</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.PeakPeriodJitter" Type="Dbl">250</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.ResourceName" Type="Str">40 MHz Onboard Clock</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.SupportAndRequireRuntimeEnableDisable" Type="Bool">false</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.TopSignalConnect" Type="Str">Clk40</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.VariableFrequency" Type="Bool">false</Property>
					<Property Name="NI.LV.FPGA.Valid" Type="Bool">true</Property>
					<Property Name="NI.LV.FPGA.Version" Type="Int">5</Property>
				</Item>
				<Item Name="IP Builder" Type="IP Builder Target">
					<Item Name="Dependencies" Type="Dependencies"/>
					<Item Name="Build Specifications" Type="Build"/>
				</Item>
				<Item Name="Mod1" Type="RIO C Series Module">
					<Property Name="crio.Calibration" Type="Str">1</Property>
					<Property Name="crio.Location" Type="Str">Slot 1</Property>
					<Property Name="crio.RequiresValidation" Type="Bool">false</Property>
					<Property Name="crio.SDcounterSlaveChannelMask" Type="Str">0</Property>
					<Property Name="crio.SDCounterSlaveMasterSlot" Type="Str">0</Property>
					<Property Name="crio.SDInputFilter" Type="Str">128</Property>
					<Property Name="crio.SupportsDynamicRes" Type="Bool">false</Property>
					<Property Name="crio.Type" Type="Str">NI 9853</Property>
					<Property Name="cRIOModule.AutoStart0" Type="Str">true</Property>
					<Property Name="cRIOModule.AutoStart1" Type="Str">true</Property>
					<Property Name="cRIOModule.BaudRate0" Type="Str">21</Property>
					<Property Name="cRIOModule.BaudRate1" Type="Str">21</Property>
					<Property Name="cRIOModule.BitTiming0" Type="Str">7169</Property>
					<Property Name="cRIOModule.BitTiming1" Type="Str">7169</Property>
					<Property Name="cRIOModule.DigitalIOMode" Type="Str">0</Property>
					<Property Name="cRIOModule.EnableSpecialtyDigital" Type="Str">false</Property>
					<Property Name="cRIOModule.IDDisplay0" Type="Str">0</Property>
					<Property Name="cRIOModule.IDDisplay1" Type="Str">0</Property>
					<Property Name="cRIOModule.IDFormat0" Type="Str">0</Property>
					<Property Name="cRIOModule.IDFormat1" Type="Str">0</Property>
					<Property Name="cRIOModule.InoutFilter0" Type="Str">0</Property>
					<Property Name="cRIOModule.InoutFilter1" Type="Str">0</Property>
					<Property Name="cRIOModule.InputTimeout0" Type="Str">10000</Property>
					<Property Name="cRIOModule.InputTimeout1" Type="Str">10000</Property>
					<Property Name="cRIOModule.ListenOnly0" Type="Str">false</Property>
					<Property Name="cRIOModule.ListenOnly1" Type="Str">false</Property>
					<Property Name="cRIOModule.ModuleClock0" Type="Str">1</Property>
					<Property Name="cRIOModule.ModuleClock1" Type="Str">255</Property>
					<Property Name="cRIOModule.ModuleType0" Type="Str">3</Property>
					<Property Name="cRIOModule.ModuleType1" Type="Str">3</Property>
					<Property Name="cRIOModule.OutputTimeout0" Type="Str">10000</Property>
					<Property Name="cRIOModule.OutputTimeout1" Type="Str">10000</Property>
					<Property Name="cRIOModule.SelectedU32IDs0" Type="Str"></Property>
					<Property Name="cRIOModule.SelectedU32IDs1" Type="Str"></Property>
					<Property Name="cRIOModule.SJA1000Code0" Type="Str">0</Property>
					<Property Name="cRIOModule.SJA1000Code1" Type="Str">0</Property>
					<Property Name="cRIOModule.SJA1000FilteMask0" Type="Str">-1</Property>
					<Property Name="cRIOModule.SJA1000FilteMask1" Type="Str">-1</Property>
					<Property Name="cRIOModule.SJA1000FilterMode0" Type="Str">1</Property>
					<Property Name="cRIOModule.SJA1000FilterMode1" Type="Str">1</Property>
					<Property Name="cRIOModule.SpecifyBitTiming0" Type="Str">false</Property>
					<Property Name="cRIOModule.SpecifyBitTiming1" Type="Str">false</Property>
					<Property Name="cRIOModule.Termination0" Type="Str">0</Property>
					<Property Name="cRIOModule.Termination1" Type="Str">0</Property>
					<Property Name="FPGA.PersistentID" Type="Str">{847971E5-33D5-4829-BA79-05359A6E8B21}</Property>
				</Item>
				<Item Name="FPGA 64bit Timer.vi" Type="VI" URL="../FPGA 64bit Timer.vi">
					<Property Name="configString.guid" Type="Str">{04E10E0D-C6CA-4C2E-ACDB-E090AA7DBF28}resource=/crio_Mod1/CAN0;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\RIO\nicrio_985x_controls.llb\CAN_IO_IONode Data Type.ctl{3E7C025C-2602-433B-A6B5-AF161FFB98E1}resource=/Scan Clock;0;ReadMethodType=bool{5F5116D2-4A6F-4EEA-A7F5-E0DD63C2404C}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{847971E5-33D5-4829-BA79-05359A6E8B21}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9853,cRIOModule.AutoStart0=true,cRIOModule.AutoStart1=true,cRIOModule.BaudRate0=21,cRIOModule.BaudRate1=21,cRIOModule.BitTiming0=7169,cRIOModule.BitTiming1=7169,cRIOModule.IDDisplay0=0,cRIOModule.IDDisplay1=0,cRIOModule.IDFormat0=0,cRIOModule.IDFormat1=0,cRIOModule.InoutFilter0=0,cRIOModule.InoutFilter1=0,cRIOModule.InputTimeout0=10000,cRIOModule.InputTimeout1=10000,cRIOModule.ListenOnly0=false,cRIOModule.ListenOnly1=false,cRIOModule.ModuleClock0=1,cRIOModule.ModuleClock1=255,cRIOModule.ModuleType0=3,cRIOModule.ModuleType1=3,cRIOModule.OutputTimeout0=10000,cRIOModule.OutputTimeout1=10000,cRIOModule.SelectedU32IDs0=,cRIOModule.SelectedU32IDs1=,cRIOModule.SJA1000Code0=0,cRIOModule.SJA1000Code1=0,cRIOModule.SJA1000FilteMask0=-1,cRIOModule.SJA1000FilteMask1=-1,cRIOModule.SJA1000FilterMode0=1,cRIOModule.SJA1000FilterMode1=1,cRIOModule.SpecifyBitTiming0=false,cRIOModule.SpecifyBitTiming1=false,cRIOModule.Termination0=0,cRIOModule.Termination1=0[crioConfig.End]{966F80AB-ED2D-49CE-999A-D496CDC49418}ArbitrationForOutputData=NeverArbitrate;NumberOfSyncRegistersForOutputData=1;NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA LED;0;ReadMethodType=bool;WriteMethodType=bool{9BD83521-8B19-4FFF-A1EE-2EBB561327EE}"ControlLogic=0;NumberOfElements=2047;Type=2;ReadArbs=Arbitrate if Multiple Requestors Only;ElementsPerRead=1;WriteArbs=Arbitrate if Multiple Requestors Only;ElementsPerWrite=1;Implementation=2;CAN1 - FIFO;DataType=1000800000000001000940070003553332000100000000000000000000;DisableOnOverflowUnderflow=FALSE"{B16E35CD-2A03-4B05-9280-0400110868B0}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{B896B164-FF59-4350-B595-B3396D0DA6BE}resource=/crio_Mod1/CAN1;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\RIO\nicrio_985x_controls.llb\CAN_IO_IONode Data Type.ctl{E3FAA6CD-DFAE-409F-8A1E-C322D14F7517}resource=/Chassis Temperature;0;ReadMethodType=i16{FA452095-4F07-4124-BDD4-27C24FD8F9CE}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolcRIO-9063/Clk40/falsefalseFPGA_EXECUTION_MODEFPGA_TARGETFPGA_TARGET_CLASSCRIO_9063FPGA_TARGET_FAMILYZYNQTARGET_TYPEFPGA/[rSeriesConfig.Begin][rSeriesConfig.End]</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;CAN1 - FIFO"ControlLogic=0;NumberOfElements=2047;Type=2;ReadArbs=Arbitrate if Multiple Requestors Only;ElementsPerRead=1;WriteArbs=Arbitrate if Multiple Requestors Only;ElementsPerWrite=1;Implementation=2;CAN1 - FIFO;DataType=1000800000000001000940070003553332000100000000000000000000;DisableOnOverflowUnderflow=FALSE"Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9063/Clk40/falsefalseFPGA_EXECUTION_MODEFPGA_TARGETFPGA_TARGET_CLASSCRIO_9063FPGA_TARGET_FAMILYZYNQTARGET_TYPEFPGA/[rSeriesConfig.Begin][rSeriesConfig.End]Mod1/CAN0resource=/crio_Mod1/CAN0;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\RIO\nicrio_985x_controls.llb\CAN_IO_IONode Data Type.ctlMod1/CAN1resource=/crio_Mod1/CAN1;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\RIO\nicrio_985x_controls.llb\CAN_IO_IONode Data Type.ctlMod1[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9853,cRIOModule.AutoStart0=true,cRIOModule.AutoStart1=true,cRIOModule.BaudRate0=21,cRIOModule.BaudRate1=21,cRIOModule.BitTiming0=7169,cRIOModule.BitTiming1=7169,cRIOModule.IDDisplay0=0,cRIOModule.IDDisplay1=0,cRIOModule.IDFormat0=0,cRIOModule.IDFormat1=0,cRIOModule.InoutFilter0=0,cRIOModule.InoutFilter1=0,cRIOModule.InputTimeout0=10000,cRIOModule.InputTimeout1=10000,cRIOModule.ListenOnly0=false,cRIOModule.ListenOnly1=false,cRIOModule.ModuleClock0=1,cRIOModule.ModuleClock1=255,cRIOModule.ModuleType0=3,cRIOModule.ModuleType1=3,cRIOModule.OutputTimeout0=10000,cRIOModule.OutputTimeout1=10000,cRIOModule.SelectedU32IDs0=,cRIOModule.SelectedU32IDs1=,cRIOModule.SJA1000Code0=0,cRIOModule.SJA1000Code1=0,cRIOModule.SJA1000FilteMask0=-1,cRIOModule.SJA1000FilteMask1=-1,cRIOModule.SJA1000FilterMode0=1,cRIOModule.SJA1000FilterMode1=1,cRIOModule.SpecifyBitTiming0=false,cRIOModule.SpecifyBitTiming1=false,cRIOModule.Termination0=0,cRIOModule.Termination1=0[crioConfig.End]Scan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolUSER FPGA LEDArbitrationForOutputData=NeverArbitrate;NumberOfSyncRegistersForOutputData=1;NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA LED;0;ReadMethodType=bool;WriteMethodType=bool</Property>
					<Property Name="NI.LV.FPGA.InterfaceBitfile" Type="Str">C:\Users\Rick\Desktop\VCU-VEHICLE MODEL\FPGA Bitfiles\VCU-VEHICLEMODEL_FPGATarget_FPGA64bitTimer_R2k0TZlzavE.lvbitx</Property>
				</Item>
				<Item Name="Basic (FPGA) CAN Engine .vi" Type="VI" URL="../Basic (FPGA) CAN Engine .vi">
					<Property Name="BuildSpec" Type="Str">{4E79F681-B3B4-4E89-866E-960C0914DC11}</Property>
					<Property Name="configString.guid" Type="Str">{04E10E0D-C6CA-4C2E-ACDB-E090AA7DBF28}resource=/crio_Mod1/CAN0;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\RIO\nicrio_985x_controls.llb\CAN_IO_IONode Data Type.ctl{3E7C025C-2602-433B-A6B5-AF161FFB98E1}resource=/Scan Clock;0;ReadMethodType=bool{5F5116D2-4A6F-4EEA-A7F5-E0DD63C2404C}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{847971E5-33D5-4829-BA79-05359A6E8B21}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9853,cRIOModule.AutoStart0=true,cRIOModule.AutoStart1=true,cRIOModule.BaudRate0=21,cRIOModule.BaudRate1=21,cRIOModule.BitTiming0=7169,cRIOModule.BitTiming1=7169,cRIOModule.IDDisplay0=0,cRIOModule.IDDisplay1=0,cRIOModule.IDFormat0=0,cRIOModule.IDFormat1=0,cRIOModule.InoutFilter0=0,cRIOModule.InoutFilter1=0,cRIOModule.InputTimeout0=10000,cRIOModule.InputTimeout1=10000,cRIOModule.ListenOnly0=false,cRIOModule.ListenOnly1=false,cRIOModule.ModuleClock0=1,cRIOModule.ModuleClock1=255,cRIOModule.ModuleType0=3,cRIOModule.ModuleType1=3,cRIOModule.OutputTimeout0=10000,cRIOModule.OutputTimeout1=10000,cRIOModule.SelectedU32IDs0=,cRIOModule.SelectedU32IDs1=,cRIOModule.SJA1000Code0=0,cRIOModule.SJA1000Code1=0,cRIOModule.SJA1000FilteMask0=-1,cRIOModule.SJA1000FilteMask1=-1,cRIOModule.SJA1000FilterMode0=1,cRIOModule.SJA1000FilterMode1=1,cRIOModule.SpecifyBitTiming0=false,cRIOModule.SpecifyBitTiming1=false,cRIOModule.Termination0=0,cRIOModule.Termination1=0[crioConfig.End]{966F80AB-ED2D-49CE-999A-D496CDC49418}ArbitrationForOutputData=NeverArbitrate;NumberOfSyncRegistersForOutputData=1;NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA LED;0;ReadMethodType=bool;WriteMethodType=bool{9BD83521-8B19-4FFF-A1EE-2EBB561327EE}"ControlLogic=0;NumberOfElements=2047;Type=2;ReadArbs=Arbitrate if Multiple Requestors Only;ElementsPerRead=1;WriteArbs=Arbitrate if Multiple Requestors Only;ElementsPerWrite=1;Implementation=2;CAN1 - FIFO;DataType=1000800000000001000940070003553332000100000000000000000000;DisableOnOverflowUnderflow=FALSE"{B16E35CD-2A03-4B05-9280-0400110868B0}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{B896B164-FF59-4350-B595-B3396D0DA6BE}resource=/crio_Mod1/CAN1;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\RIO\nicrio_985x_controls.llb\CAN_IO_IONode Data Type.ctl{E3FAA6CD-DFAE-409F-8A1E-C322D14F7517}resource=/Chassis Temperature;0;ReadMethodType=i16{FA452095-4F07-4124-BDD4-27C24FD8F9CE}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolcRIO-9063/Clk40/falsefalseFPGA_EXECUTION_MODEFPGA_TARGETFPGA_TARGET_CLASSCRIO_9063FPGA_TARGET_FAMILYZYNQTARGET_TYPEFPGA/[rSeriesConfig.Begin][rSeriesConfig.End]</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;CAN1 - FIFO"ControlLogic=0;NumberOfElements=2047;Type=2;ReadArbs=Arbitrate if Multiple Requestors Only;ElementsPerRead=1;WriteArbs=Arbitrate if Multiple Requestors Only;ElementsPerWrite=1;Implementation=2;CAN1 - FIFO;DataType=1000800000000001000940070003553332000100000000000000000000;DisableOnOverflowUnderflow=FALSE"Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9063/Clk40/falsefalseFPGA_EXECUTION_MODEFPGA_TARGETFPGA_TARGET_CLASSCRIO_9063FPGA_TARGET_FAMILYZYNQTARGET_TYPEFPGA/[rSeriesConfig.Begin][rSeriesConfig.End]Mod1/CAN0resource=/crio_Mod1/CAN0;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\RIO\nicrio_985x_controls.llb\CAN_IO_IONode Data Type.ctlMod1/CAN1resource=/crio_Mod1/CAN1;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\RIO\nicrio_985x_controls.llb\CAN_IO_IONode Data Type.ctlMod1[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9853,cRIOModule.AutoStart0=true,cRIOModule.AutoStart1=true,cRIOModule.BaudRate0=21,cRIOModule.BaudRate1=21,cRIOModule.BitTiming0=7169,cRIOModule.BitTiming1=7169,cRIOModule.IDDisplay0=0,cRIOModule.IDDisplay1=0,cRIOModule.IDFormat0=0,cRIOModule.IDFormat1=0,cRIOModule.InoutFilter0=0,cRIOModule.InoutFilter1=0,cRIOModule.InputTimeout0=10000,cRIOModule.InputTimeout1=10000,cRIOModule.ListenOnly0=false,cRIOModule.ListenOnly1=false,cRIOModule.ModuleClock0=1,cRIOModule.ModuleClock1=255,cRIOModule.ModuleType0=3,cRIOModule.ModuleType1=3,cRIOModule.OutputTimeout0=10000,cRIOModule.OutputTimeout1=10000,cRIOModule.SelectedU32IDs0=,cRIOModule.SelectedU32IDs1=,cRIOModule.SJA1000Code0=0,cRIOModule.SJA1000Code1=0,cRIOModule.SJA1000FilteMask0=-1,cRIOModule.SJA1000FilteMask1=-1,cRIOModule.SJA1000FilterMode0=1,cRIOModule.SJA1000FilterMode1=1,cRIOModule.SpecifyBitTiming0=false,cRIOModule.SpecifyBitTiming1=false,cRIOModule.Termination0=0,cRIOModule.Termination1=0[crioConfig.End]Scan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolUSER FPGA LEDArbitrationForOutputData=NeverArbitrate;NumberOfSyncRegistersForOutputData=1;NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA LED;0;ReadMethodType=bool;WriteMethodType=bool</Property>
					<Property Name="NI.LV.FPGA.InterfaceBitfile" Type="Str">C:\Users\Rick\Dropbox\RTsim-VehicleSec\VIs\VCU-VEHICLE MODEL\FPGA Bitfiles\VCU-VEHICLEMODEL_FPGATarget_CANBasic(FPGA)_WVt1gIpoBPw.lvbitx</Property>
				</Item>
				<Item Name="CAN1 - FIFO" Type="FPGA FIFO">
					<Property Name="Actual Number of Elements" Type="UInt">2047</Property>
					<Property Name="Arbitration for Read" Type="UInt">1</Property>
					<Property Name="Arbitration for Write" Type="UInt">1</Property>
					<Property Name="Control Logic" Type="UInt">0</Property>
					<Property Name="Data Type" Type="UInt">7</Property>
					<Property Name="Disable on Overflow/Underflow" Type="Bool">false</Property>
					<Property Name="fifo.configuration" Type="Str">"ControlLogic=0;NumberOfElements=2047;Type=2;ReadArbs=Arbitrate if Multiple Requestors Only;ElementsPerRead=1;WriteArbs=Arbitrate if Multiple Requestors Only;ElementsPerWrite=1;Implementation=2;CAN1 - FIFO;DataType=1000800000000001000940070003553332000100000000000000000000;DisableOnOverflowUnderflow=FALSE"</Property>
					<Property Name="fifo.configured" Type="Bool">true</Property>
					<Property Name="fifo.projectItemValid" Type="Bool">true</Property>
					<Property Name="fifo.valid" Type="Bool">true</Property>
					<Property Name="fifo.version" Type="Int">12</Property>
					<Property Name="FPGA.PersistentID" Type="Str">{9BD83521-8B19-4FFF-A1EE-2EBB561327EE}</Property>
					<Property Name="Local" Type="Bool">false</Property>
					<Property Name="Memory Type" Type="UInt">2</Property>
					<Property Name="Number Of Elements Per Read" Type="UInt">1</Property>
					<Property Name="Number Of Elements Per Write" Type="UInt">1</Property>
					<Property Name="Requested Number of Elements" Type="UInt">2040</Property>
					<Property Name="Type" Type="UInt">2</Property>
					<Property Name="Type Descriptor" Type="Str">1000800000000001000940070003553332000100000000000000000000</Property>
				</Item>
				<Item Name="Dependencies" Type="Dependencies">
					<Item Name="vi.lib" Type="Folder">
						<Item Name="CAN_IO_Frame Cluster.ctl" Type="VI" URL="/&lt;vilib&gt;/LabVIEW Targets/FPGA/RIO/nicrio_985x_controls.llb/CAN_IO_Frame Cluster.ctl"/>
						<Item Name="CAN_IO_Frame Type.ctl" Type="VI" URL="/&lt;vilib&gt;/LabVIEW Targets/FPGA/RIO/nicrio_985x_controls.llb/CAN_IO_Frame Type.ctl"/>
						<Item Name="CAN_IO_Comm State.ctl" Type="VI" URL="/&lt;vilib&gt;/LabVIEW Targets/FPGA/RIO/nicrio_985x_controls.llb/CAN_IO_Comm State.ctl"/>
						<Item Name="lvSimController.dll" Type="Document" URL="/&lt;vilib&gt;/rvi/Simulation/lvSimController.dll"/>
					</Item>
				</Item>
				<Item Name="Build Specifications" Type="Build">
					<Item Name="CAN Basic (FPGA)" Type="{F4C5E96F-7410-48A5-BB87-3559BC9B167F}">
						<Property Name="AllowEnableRemoval" Type="Bool">false</Property>
						<Property Name="BuildSpecDecription" Type="Str"></Property>
						<Property Name="BuildSpecName" Type="Str">CAN Basic (FPGA)</Property>
						<Property Name="Comp.BitfileName" Type="Str">VCU-VEHICLEMODEL_FPGATarget_CANBasic(FPGA)_WVt1gIpoBPw.lvbitx</Property>
						<Property Name="Comp.CustomXilinxParameters" Type="Str"></Property>
						<Property Name="Comp.MaxFanout" Type="Int">-1</Property>
						<Property Name="Comp.RandomSeed" Type="Bool">false</Property>
						<Property Name="Comp.Version.Build" Type="Int">0</Property>
						<Property Name="Comp.Version.Fix" Type="Int">0</Property>
						<Property Name="Comp.Version.Major" Type="Int">1</Property>
						<Property Name="Comp.Version.Minor" Type="Int">0</Property>
						<Property Name="Comp.VersionAutoIncrement" Type="Bool">false</Property>
						<Property Name="Comp.Vivado.EnableMultiThreading" Type="Bool">true</Property>
						<Property Name="Comp.Vivado.OptDirective" Type="Str"></Property>
						<Property Name="Comp.Vivado.PhysOptDirective" Type="Str"></Property>
						<Property Name="Comp.Vivado.PlaceDirective" Type="Str"></Property>
						<Property Name="Comp.Vivado.RouteDirective" Type="Str"></Property>
						<Property Name="Comp.Vivado.RunPowerOpt" Type="Bool">false</Property>
						<Property Name="Comp.Vivado.Strategy" Type="Str">Default</Property>
						<Property Name="Comp.Xilinx.DesignStrategy" Type="Str">balanced</Property>
						<Property Name="Comp.Xilinx.MapEffort" Type="Str">default(noTiming)</Property>
						<Property Name="Comp.Xilinx.ParEffort" Type="Str">standard</Property>
						<Property Name="Comp.Xilinx.SynthEffort" Type="Str">normal</Property>
						<Property Name="Comp.Xilinx.SynthGoal" Type="Str">speed</Property>
						<Property Name="Comp.Xilinx.UseRecommended" Type="Bool">true</Property>
						<Property Name="DefaultBuildSpec" Type="Bool">true</Property>
						<Property Name="DestinationDirectory" Type="Path">FPGA Bitfiles</Property>
						<Property Name="NI.LV.FPGA.LastCompiledBitfilePath" Type="Path">/C/Users/Rick/Dropbox/RTsim-VehicleSec/VIs/VCU-VEHICLE MODEL/FPGA Bitfiles/VCU-VEHICLEMODEL_FPGATarget_CANBasic(FPGA)_WVt1gIpoBPw.lvbitx</Property>
						<Property Name="NI.LV.FPGA.LastCompiledBitfilePathRelativeToProject" Type="Path">FPGA Bitfiles/VCU-VEHICLEMODEL_FPGATarget_CANBasic(FPGA)_WVt1gIpoBPw.lvbitx</Property>
						<Property Name="ProjectPath" Type="Path">/C/Users/Rick/Dropbox/RTsim-VehicleSec/VIs/VCU-VEHICLE MODEL/VCU-VEHICLE MODEL.lvproj</Property>
						<Property Name="RelativePath" Type="Bool">true</Property>
						<Property Name="RunWhenLoaded" Type="Bool">false</Property>
						<Property Name="SupportDownload" Type="Bool">true</Property>
						<Property Name="SupportResourceEstimation" Type="Bool">false</Property>
						<Property Name="TargetName" Type="Str">FPGA Target</Property>
						<Property Name="TopLevelVI" Type="Ref">/RT CompactRIO Target/Chassis/FPGA Target/Basic (FPGA) CAN Engine .vi</Property>
					</Item>
					<Item Name="FPGA 64bit Timer" Type="{F4C5E96F-7410-48A5-BB87-3559BC9B167F}">
						<Property Name="AllowEnableRemoval" Type="Bool">false</Property>
						<Property Name="BuildSpecDecription" Type="Str"></Property>
						<Property Name="BuildSpecName" Type="Str">FPGA 64bit Timer</Property>
						<Property Name="Comp.BitfileName" Type="Str">VCU-VEHICLEMODEL_FPGATarget_FPGA64bitTimer_R2k0TZlzavE.lvbitx</Property>
						<Property Name="Comp.CustomXilinxParameters" Type="Str"></Property>
						<Property Name="Comp.MaxFanout" Type="Int">-1</Property>
						<Property Name="Comp.RandomSeed" Type="Bool">false</Property>
						<Property Name="Comp.Version.Build" Type="Int">0</Property>
						<Property Name="Comp.Version.Fix" Type="Int">0</Property>
						<Property Name="Comp.Version.Major" Type="Int">1</Property>
						<Property Name="Comp.Version.Minor" Type="Int">0</Property>
						<Property Name="Comp.VersionAutoIncrement" Type="Bool">false</Property>
						<Property Name="Comp.Vivado.EnableMultiThreading" Type="Bool">true</Property>
						<Property Name="Comp.Vivado.OptDirective" Type="Str"></Property>
						<Property Name="Comp.Vivado.PhysOptDirective" Type="Str"></Property>
						<Property Name="Comp.Vivado.PlaceDirective" Type="Str"></Property>
						<Property Name="Comp.Vivado.RouteDirective" Type="Str"></Property>
						<Property Name="Comp.Vivado.RunPowerOpt" Type="Bool">false</Property>
						<Property Name="Comp.Vivado.Strategy" Type="Str">Default</Property>
						<Property Name="Comp.Xilinx.DesignStrategy" Type="Str">balanced</Property>
						<Property Name="Comp.Xilinx.MapEffort" Type="Str">default(noTiming)</Property>
						<Property Name="Comp.Xilinx.ParEffort" Type="Str">standard</Property>
						<Property Name="Comp.Xilinx.SynthEffort" Type="Str">normal</Property>
						<Property Name="Comp.Xilinx.SynthGoal" Type="Str">speed</Property>
						<Property Name="Comp.Xilinx.UseRecommended" Type="Bool">true</Property>
						<Property Name="DefaultBuildSpec" Type="Bool">true</Property>
						<Property Name="DestinationDirectory" Type="Path">FPGA Bitfiles</Property>
						<Property Name="NI.LV.FPGA.LastCompiledBitfilePath" Type="Path">/C/Users/Rick/Desktop/VCU-VEHICLE MODEL/FPGA Bitfiles/VCU-VEHICLEMODEL_FPGATarget_FPGA64bitTimer_R2k0TZlzavE.lvbitx</Property>
						<Property Name="NI.LV.FPGA.LastCompiledBitfilePathRelativeToProject" Type="Path">FPGA Bitfiles/VCU-VEHICLEMODEL_FPGATarget_FPGA64bitTimer_R2k0TZlzavE.lvbitx</Property>
						<Property Name="ProjectPath" Type="Path">/C/Users/Rick/Desktop/VCU-VEHICLE MODEL/VCU-VEHICLE MODEL.lvproj</Property>
						<Property Name="RelativePath" Type="Bool">true</Property>
						<Property Name="RunWhenLoaded" Type="Bool">false</Property>
						<Property Name="SupportDownload" Type="Bool">true</Property>
						<Property Name="SupportResourceEstimation" Type="Bool">false</Property>
						<Property Name="TargetName" Type="Str">FPGA Target</Property>
						<Property Name="TopLevelVI" Type="Ref">/RT CompactRIO Target/Chassis/FPGA Target/FPGA 64bit Timer.vi</Property>
					</Item>
				</Item>
			</Item>
		</Item>
		<Item Name="VCU MODEL CAN0.vi" Type="VI" URL="../VCU MODEL CAN0.vi"/>
		<Item Name="VEHICLE MODEL CAN1.vi" Type="VI" URL="../VEHICLE MODEL CAN1.vi"/>
		<Item Name="Stream to Network.vi" Type="VI" URL="../Stream to Network.vi"/>
		<Item Name="UDP_Stream(DMA).vi" Type="VI" URL="../UDP_Stream(DMA).vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Search and Replace Pattern.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Search and Replace Pattern.vi"/>
				<Item Name="Find Tag.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Find Tag.vi"/>
				<Item Name="Set Bold Text.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Set Bold Text.vi"/>
				<Item Name="Format Message String.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Format Message String.vi"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="Error Code Database.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Code Database.vi"/>
				<Item Name="GetRTHostConnectedProp.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/GetRTHostConnectedProp.vi"/>
				<Item Name="TagReturnType.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/TagReturnType.ctl"/>
				<Item Name="Check Special Tags.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Check Special Tags.vi"/>
				<Item Name="DialogTypeEnum.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/DialogTypeEnum.ctl"/>
				<Item Name="Set String Value.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Set String Value.vi"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="eventvkey.ctl" Type="VI" URL="/&lt;vilib&gt;/event_ctls.llb/eventvkey.ctl"/>
				<Item Name="ErrWarn.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/ErrWarn.ctl"/>
				<Item Name="Details Display Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Details Display Dialog.vi"/>
				<Item Name="GetHelpDir.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/GetHelpDir.vi"/>
				<Item Name="BuildHelpPath.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/BuildHelpPath.vi"/>
				<Item Name="LVBoundsTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVBoundsTypeDef.ctl"/>
				<Item Name="Get String Text Bounds.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Get String Text Bounds.vi"/>
				<Item Name="Get Text Rect.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Get Text Rect.vi"/>
				<Item Name="Convert property node font to graphics font.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Convert property node font to graphics font.vi"/>
				<Item Name="Longest Line Length in Pixels.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Longest Line Length in Pixels.vi"/>
				<Item Name="LVRectTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVRectTypeDef.ctl"/>
				<Item Name="Three Button Dialog CORE.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Three Button Dialog CORE.vi"/>
				<Item Name="Three Button Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Three Button Dialog.vi"/>
				<Item Name="Not Found Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Not Found Dialog.vi"/>
				<Item Name="General Error Handler Core CORE.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/General Error Handler Core CORE.vi"/>
				<Item Name="DialogType.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/DialogType.ctl"/>
				<Item Name="General Error Handler.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/General Error Handler.vi"/>
				<Item Name="Simple Error Handler.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Simple Error Handler.vi"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
			</Item>
			<Item Name="NiFpgaLv.dll" Type="Document" URL="NiFpgaLv.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="Position_speed.vi" Type="VI" URL="../Position_speed.vi"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
