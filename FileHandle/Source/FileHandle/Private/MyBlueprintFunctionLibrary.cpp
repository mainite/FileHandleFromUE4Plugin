// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "Runtime/Core/Public/HAL/FileManagerGeneric.h"


FString UMyBlueprintFunctionLibrary::ReadStringToFile(FString Dir)
{
	FString Result;
	FFileHelper::LoadFileToString(Result, *Dir);
	return Result;
}

void UMyBlueprintFunctionLibrary::WriteStringToFile(FString FileName, FString content)
{
	FFileHelper::SaveStringToFile(content, *FileName);
}

TArray<FString> UMyBlueprintFunctionLibrary::FindFiles(FString Path, FString Filter, bool Files, bool Directory)
{
	TArray<FString> FilePathList;
	FilePathList.Empty();
	FFileManagerGeneric::Get().FindFilesRecursive(FilePathList, *Path, *Filter, Files, Directory);
	return FilePathList;
}

bool UMyBlueprintFunctionLibrary::MoveFileTo(FString To, FString From)
{
	return IFileManager::Get().Move(*To, *From);
}

bool UMyBlueprintFunctionLibrary::DeleteFile(FString FilePath)
{
	return IFileManager::Get().Delete(*FilePath);
}

void UMyBlueprintFunctionLibrary::OpenFile(FString FilePath)
{
	FPlatformProcess::CreateProc(*FilePath, nullptr, true, false, false, nullptr, 0, nullptr, nullptr);
}

void UMyBlueprintFunctionLibrary::CreateDic(FString filePath)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	PlatformFile.CreateDirectory(*filePath);

}

void UMyBlueprintFunctionLibrary::DeleteDic(FString filePath)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	PlatformFile.DeleteDirectory(*filePath);
}
