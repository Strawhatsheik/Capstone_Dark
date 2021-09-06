// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"

//Constructor
AMainGameMode::AMainGameMode()
{

	//From tutorial
		//Inconcstructor he sets dcore to 0 initially

//From tutorial
	//Inconcstructor he sets dcore to 0 initially

	Score = 0;
}

//From tutorial

void AMainGameMode::SetMainText(FString value)
{
	//Sets scorepoints
	TextForBox = value;

}


FString AMainGameMode::GetMainText()
{
	//Gets scorepoints
	return TextForBox;
}