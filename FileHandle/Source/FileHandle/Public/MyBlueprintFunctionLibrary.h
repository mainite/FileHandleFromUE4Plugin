// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class FILEHANDLE_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "FileHandle")
		static FString ReadStringToFile(FString Dir);

	UFUNCTION(BlueprintCallable, Category = "FileHandle")
		static void WriteStringToFile(FString FileName, FString content);

	UFUNCTION(BlueprintCallable, Category = "File operation")
		static TArray<FString> FindFiles(FString Path, FString Filter, bool Files, bool Directory);

	UFUNCTION(BlueprintCallable, Category = "FileHandle")
		static bool MoveFileTo(FString To, FString From);

	UFUNCTION(BlueprintCallable, Category = "FileHandle")
		static bool CopyFileTo(FString To, FString From);

	UFUNCTION(BlueprintCallable, Category = "FileHandle")
		static bool DeleteFile(FString FilePath);

	UFUNCTION(BlueprintCallable, Category = "FileHandle")
		static void   OpenFile(FString FilePath);

	UFUNCTION(BlueprintCallable, Category = "FileHandle")
		static void CreateDic(FString filePath);
	
	UFUNCTION(BlueprintCallable, Category = "FileHandle")
		static void DeleteDic(FString filePath);


	
};
