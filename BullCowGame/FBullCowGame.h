/* 
	The Game logic (no view code or direct user interaction).
	The game is a simple guess the word game based on Mastermind.
*/
#pragma once
#include <string>

// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

/*
	Struct for counting bulls & cows when playing.
*/
struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

/*
	Enumeration with the different status of the user guess.
*/
enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
};

/*
	Class of the Bull&Cow Game with all the logical functions,
	constructor and private variables needed to make the game 
	runs correctly.
*/
class FBullCowGame 
{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool isGameWon() const;

	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	// see constructor for initialization
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};