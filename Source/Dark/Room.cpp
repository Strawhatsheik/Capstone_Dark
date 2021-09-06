// Fill out your copyright notice in the Description page of Project Settings.


#include "Room.h"
#include "Logging/LogVerbosity.h"
#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"

#include <Runtime/Core/Public/Windows/COMPointer.h>


// Sets default values
ARoom::ARoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

//Overloaded and preferred constructor. 
//Takes a string with filename as paramter to load level
ARoom::ARoom(FString LevelFile)
{

}

// Called when the game starts or when spawned
void ARoom::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ARoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


//This function takes a string (filename) as parameter. 
//It checks to make sure the file can be loaded, and if so, loads it into level descriptions
void ARoom::LoadLevel(FString LevelFile)
{

	
	
	//Retrieve full filepath
	//String fileNameLvl = FPaths::ProjectContentDir() / TEXT("Files/LevelTest1.txt");
	
	//Display filepath for testing 
	UE_LOG(LogTemp, Warning, TEXT("%s"), *LevelFile);

	//Checking file exists and therefore can be opened
	if (FPaths::FileExists(*LevelFile))
	{
		//TArray<FString> LevelInfo;

		//If the file was fouond, now it can be loaded into array 'LevelInfo'
		if (FFileHelper::LoadFileToStringArray(LevelInfo, *LevelFile))
		{
			
			// 
			//Assign values from array and populate descriptions.
			//Note, it skips 0 and every third line after 2 to skip identifier lines left for designers
			//Need to test, try printing first
			OpeningDesc = LevelInfo[1];
			Look1 = LevelInfo[3];
			Look2 = LevelInfo[4];
			Look3 = LevelInfo[5];
			Listen1 = LevelInfo[7];
			Listen2 = LevelInfo[8];
			Listen3 = LevelInfo[9];
			Touch1 = LevelInfo[11];
			Touch2 = LevelInfo[12];
			Touch3 = LevelInfo[13];
			Taste1 = LevelInfo[15];
			Taste2 = LevelInfo[16];
			Taste3 = LevelInfo[17];
			Smell1 = LevelInfo[19];
			Smell2 = LevelInfo[20];
			Smell3 = LevelInfo[21];
			Move1 = LevelInfo[23];
			Move2 = LevelInfo[24];
			Move3 = LevelInfo[25];
			
			//Taste1 = LevelInfo[13];
			//UE_LOG(LogTemp, Warning, TEXT("%s"), *Taste1);
			
			/*for (auto& Str : LevelInfo)
			{
				FString ToBePrinted;
				ToBePrinted += Str;

				//Remember the asterisk dereferences it to a be a char now
				UE_LOG(LogTemp, Warning, TEXT("%s"), *ToBePrinted);
			}
			*/

			//apparently this is he rexcommended way to iterate over array:
			//FString JoinedStr;
			//for (auto& Str : StrArr)
			/** {
				JoinedStr += Str;
				JoinedStr += TEXT(" ");
			}*/
			// JoinedStr == "Hello Brave World of Tomorrow ! "
		}
		else//File could not be found?
		{
			UE_LOG(LogTemp, Warning, TEXT("No file"));
		}
	}
	else //If the file couldn't be found/loaded, display error message in log
	{
		
		UE_LOG(LogTemp, Warning, TEXT("File not found"));
	}
}

//The following retrieve the current descritpiton and pass it to MainTextBox when called
FString ARoom::GetLookDescription()
{
	return CurrentLook;
}

FString ARoom::GetListenDescription()
{
	return CurrentListen;

}

FString ARoom::GetTasteDescription()
{
	return CurrentTaste;

}

FString ARoom::GetTouchDescription()
{
	return CurrentTouch;

}

FString ARoom::GetMoveDescription()
{
	return CurrentMove;

}

FString ARoom::GetSmellDescription()
{
	return CurrentSmell;

}
///End functions that pass current descriptions


//The following take in new argument and updates current description that will be passed when called to MainTextBox
void ARoom::SetSightDescription(FString NewCurrent)
{
	CurrentLook = NewCurrent;
	//StoryUserWidget->MainText->SetText(FText::FromString(CurrentLook));

}

void ARoom::SetListenDescription(FString NewCurrent)
{
	CurrentListen = NewCurrent;
}

void ARoom::SetTasteDescription(FString NewCurrent)
{
	CurrentTaste = NewCurrent;
}

void ARoom::SetTouchDescription(FString NewCurrent)
{
	CurrentTouch = NewCurrent;
}

void ARoom::SetMoveDescription(FString NewCurrent)
{
	CurrentMove = NewCurrent;
}

void ARoom::SetSmellDescription(FString NewCurrent)
{
	CurrentSmell = NewCurrent;
}
///End functions that update descriptions