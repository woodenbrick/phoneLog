; -- Example1.iss --
; Demonstrates copying 3 files and creating an icon.

; SEE THE DOCUMENTATION FOR DETAILS ON CREATING .ISS SCRIPT FILES!

[Setup]
AppName=Phone Number Tracker
AppVerName=Phone Number Tracker 0.1
DefaultDirName={pf}\PhoneNumberTracker
DefaultGroupName=Phone Number Tracker
UninstallDisplayIcon={app}\PhoneNumberTracker.exe
Compression=lzma
SolidCompression=yes

[Files]
Source: "PhoneNumberTracker.exe"; DestDir: "{app}"
Source: "phone.png"; DestDir: "{app}"
Source: "QtCore4.dll"; DestDir: "{app}";
Source: "QtGui4.dll"; DestDir: "{app}";
Source: "QtXml4.dll"; DestDir: "{app}";
Source: "QtNetwork4.dll"; DestDir: "{app}";

[Icons]
Name: "{commonprograms}\Phone Number Tracker"; Filename: "{app}\PhoneNumberTracker.exe"
Name: "{commondesktop}\Phone Number Tracker"; Filename: "{app}\PhoneNumberTracker.exe"
