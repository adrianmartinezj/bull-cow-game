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
    if (bGameOver) 
    {
        ClearScreen();
        SetupGame();
    }
    else 
    {
        ProcessGuess(Input);
        
    }
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

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if ( Guess == HiddenWord ) 
    {
        PrintLine("You have won!");
        EndGame();
        return;
    } 

    PrintLine(TEXT("You lost a life!"));
    --Lives;

    // if ( !IsIsogram )
    // {
    //     PrintLine("There are no repeating letters, guess again.");
    // }

    if (Guess.Len() != HiddenWord.Len()) 
    {
        PrintLine(TEXT("Sorry! Try guessing again.\nYou have %i lives remaining."), Lives);
        PrintLine(TEXT("The hidden word is %i characters long."), HiddenWord.Len());
    }
    
    if (Lives <= 0) 
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The hidden word was %s."), *HiddenWord);
        EndGame();
        return;
    }

    PrintLine(TEXT("Guess again! You have %i lives left."), Lives);
}