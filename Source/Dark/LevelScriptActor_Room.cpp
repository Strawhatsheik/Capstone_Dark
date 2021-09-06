// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelScriptActor_Room.h"
#include "StoryUserWidget.h"
#include "MainGameMode.h"
#include "Room.h"


//Mayyyybbbbbeeee this is what I use to call the room object actor!!! THIS can hold all their instances. Therefore only one 
//'level' in unreal


//I need to see if this works in mutliple levels
//For delegate funtion, on clicked event
/*void UStoryUserWidget::LookButtonPressed()
{
	UWorld* MyWorld = GetWorld();
	FString CurrentMapName = MyWorld->GetMapName();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *CurrentMapName);

}*/



//Sets up the level
void ALevelScriptActor_Room::LevelSetup()
{
    //Populate with levels
   // LevelNames.Add(TEXT("Level_0"));
   // LevelNames.Add(TEXT("Level_1"));
   // LevelNames.Add(TEXT("Level_2"));

	//Spawns a room actor
	ARoom* ANewRoom = GetWorld()->SpawnActor<ARoom>();
	//Retreives level name
	UWorld* MyWorld = GetWorld();
	FString CurrentMapName = MyWorld->GetMapName();
    UE_LOG(LogTemp, Warning, TEXT("Current map name is %s"), *CurrentMapName);

    if (CurrentMapName == "UEDPIE_0_Level_0")
    {
        //Based on level name, finds the correct file
        FString fileNameLvl = FPaths::ProjectContentDir() / TEXT("Files/Level_0.txt");
        
        if (FPaths::FileExists(*fileNameLvl))
        {
            //Passes file to spawned room for setup
            ANewRoom->LoadLevel(fileNameLvl);
            UE_LOG(LogTemp, Warning, TEXT("File for Level_0 found"));
        }
        else//File could not be found?
        {
            UE_LOG(LogTemp, Warning, TEXT("File for Level_0 not found"));
        }
    }
    else if(CurrentMapName == "UEDPIE_0_Level_1")
    {
        //Based on level name, finds the correct file
        FString fileNameLvl = FPaths::ProjectContentDir() / TEXT("Files/Level_1.txt");
       
        if (FPaths::FileExists(*fileNameLvl))
        {
            //Passes file to spawned room for setup
            ANewRoom->LoadLevel(fileNameLvl);
            UE_LOG(LogTemp, Warning, TEXT("File for Level_1 found"));
        }
        else//File could not be found?
        {
            UE_LOG(LogTemp, Warning, TEXT("File for Level_1 not found"));
        }
    }
    else 
    {
        UE_LOG(LogTemp, Warning, TEXT("No level files found"));
    }


    //Ok, so you can't switcho n strings. But if I had array, could it match the type, pull in number, then affic num ber to room name and or end of filetype? 
   /* switch (CurrentMapName)
    {
        case LevelOne
            break;
    }*/
	//Based on level name, finds the correct file
//	FString fileNameLvl = FPaths::ProjectContentDir() / TEXT("Files/LevelTest1.txt");

	//Passes file to spawned room for setup
//	ANewRoom->LoadLevel(fileNameLvl);


  
    /*Example switch statement
    enumVariable = EMyEnum::itemOne;

    switch (enumVariable)
    {
    case EMyEnum::itemOne:
        //Do code
        break;

    case EMyEnum::itemTwo:
        //Do code
        break;
    case EMyEnum::itemThree:
        //Do code
        break;

    default: break;
    }
    */
}
