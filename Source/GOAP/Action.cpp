// Fill out your copyright notice in the Description page of Project Settings.


#include "Action.h"

UAction::UAction() {}

void UAction::ActionToJsonObject()
{
    FString file_path = FPaths::GetProjectFilePath();
    FString FileData = "";
    if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*file_path))
    {
        UE_LOG(LogTemp, Warning, TEXT("DID NOT FIND FILE"));
        return;
    }

    // Create Json Object and assign the action properties
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    JsonObject->SetStringField("Name", "My Action");
    JsonObject->SetNumberField("Cost", 3);

    // Write json object to string
    FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&FileData);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

    // Write the string to file
    FFileHelper::SaveStringToFile(FileData, *file_path);
    UE_LOG(LogTemp, Warning, TEXT("%s"), *FileData);
}

void UAction::JsonObjectToAction()
{
    FString file_path = FPaths::GetProjectFilePath();
    FString FileData = "";
    if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*file_path))
    {
        UE_LOG(LogTemp, Warning, TEXT("DID NOT FIND FILE"));
        return;
    }

    // Read file data into string
    FFileHelper::LoadFileToString(FileData, *file_path);
    UE_LOG(LogTemp, Warning, TEXT("%s"), *FileData);
    // Read string into Json Object
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(file_path);

    // Write Json Object data to an Action object
    if (FJsonSerializer::Deserialize(Reader, JsonObject))
    {
        FString field_name = JsonObject->GetStringField(TEXT("Name"));
    }
}

