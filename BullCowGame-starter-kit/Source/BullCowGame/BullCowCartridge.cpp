// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame(); // Setting up Game

    // PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord); // Debug line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    // if (bGameOver) 
    // {
    //     ClearScreen();
    //     SetupGame();
    // }
    // else 
    // {
    //     if ( Input == HiddenWord ) 
    //     {
    //         PrintLine("You have won!");
    //         EndGame();
    //     } 
    //     else 
    //     {
    //         if (Input.Len() != HiddenWord.Len()) {
    //             PrintLine(TEXT("The hidden word is %i letters long, you have lost!"), HiddenWord.Len());
    //             EndGame();
    //         }
    //     }
    // }
}

void UBullCowCartridge::SetupGame() 
{
    PrintLine(TEXT("Welcome to Bull + Cows!"));
    HiddenWord = TEXT("cakes");
	Lives = 4;
    bGameOver = false;
    // Welcoming the Player
    PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len()); // Magic number remove!
    // Prompt player for guess
    PrintLine(TEXT("Type in your guess...\nPress enter to continue."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine("Press enter to play again.");
}