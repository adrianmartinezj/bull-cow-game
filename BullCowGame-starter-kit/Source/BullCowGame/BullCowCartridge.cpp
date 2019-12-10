// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull + Cows!"));
    PrintLine(TEXT("Guess the 4 letter word.")); // Magic number remove!
    PrintLine(TEXT("Press Tab to begin, enter something!"));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    FString HiddenWord = TEXT("cake");
    PrintLine(Input);
    if ( Input == HiddenWord ) {
        PrintLine("That is the hidden word!");
    } else {
        PrintLine("That is wrong, you are dead!");
    }
}