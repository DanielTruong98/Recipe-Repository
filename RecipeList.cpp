#include "RecipeList.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>

//Declaration
RecipeList::RecipeList(){

}


//setters
void RecipeList::addRecipe(){

    std::string rName;
    int cTime;
    int pTime;
    std::string inputVals;
    bool ingredientInput = false;

    std::string input;

    std::cout << "Input recipe name: ";
    std::getline (std::cin, rName);
    std::cout << std::endl;

    while(true){
      std::cout << "Input cooking time: ";
      std::getline (std::cin, inputVals);
      std::stringstream myStream(inputVals);
      if (myStream >> cTime){
        break;
      }
      std::cout << "Invalid input. Enter a number.\n";
    }
    std::cout << std::endl;

    while(true){
      std::cout << "Input preparation time: ";
      std::getline (std::cin, inputVals);
      std::stringstream myStream1(inputVals);
      if (myStream1 >> pTime){
        break;
      }
      std::cout << "Invalid input. Enter a number.\n";
    }
    std::cout << std::endl;

    // Creates new Recipe object with rName, cTime, pTime
    // Ingredient and amount added to vectors in while loop
    Recipe* temp = new Recipe(rName, cTime, pTime);
    if (temp == NULL){
      std::cout << "error with new recipe" << std::endl;
      abort();
    }

    std::cout << "Input ingredient name with amount and unit after a :\n";
    std::cout << "Example: water:10ml\n";
    std::cout << "When finished inputting ingredients, type exit to leave ingredient input\n";

    while(true){
      char c = ':';
      while(true){
        std::getline(std::cin, input);
        if (input.find(c) != -1 || input == "exit"){
          break;
        }
        std::cout << "Ensure there is a colon when inputting\n";
      }
      if (input == "exit"){
          break;
      }
      size_t location = input.find(c);
      std::string tempName = input.substr(0, location);
      std::string tempAmount = input.substr(location + 1, input.size() - location);
      if (tempName != "" || tempAmount != ""){
        temp->addIngredient(tempName);
        temp->addIngredientAmount(tempAmount);
      }
    }
    temp->inputInstructions();
    listRecipe.push_back(*temp);

    ///If there is only 1 recipe in the vector
    ///Make it the current recipe
    if (listRecipe.size() == 1){
      current = &(listRecipe.front());
    }
}

void RecipeList::removeRecipe(std::string rName){
  for (auto i = listRecipe.begin(); i != listRecipe.end(); i++){
    if (i->getRecipeName() == rName){
      std::cout << "Removing " << rName << " from list.\n";
      listRecipe.erase(i);
      listRecipe.shrink_to_fit();
      return;
    }
  }
  std::cout << rName << " not found in list" << std::endl;
}

void RecipeList::changeRecipe(std::string rName){
  Recipe* target = NULL;
  std::string input;
  int selection;

  for (int i = 0; i < listRecipe.size(); i++){
    if (listRecipe[i].getRecipeName() == rName){
      target = &listRecipe[i];
    }
  }
  std::cout << "Current recipe: ";
  target->printRecipeName();
  std::cout << std::endl;

  std::cout << "Enter option number\n";
  std::cout << "1. Change recipe name.\n";
  std::cout << "2. Change recipe cooking time.\n";
  std::cout << "3. Change recipe preparation time.\n";
  std::cout << "4. Insert instruction.\n";
  std::cout << "5. Remove instruction.\n";
  std::cout << "6. Insert ingredient.\n";
  std::cout << "7. Remove ingredient.\n";
  std::cout << "\n";
  while(true){
    std::getline (std::cin, input);
    std::stringstream myStream(input);
    if (myStream >> selection){
      if (selection >= 1 && selection <= 7){
        break;
      }
    }
    std::cout << "Invalid input. Enter a number between 1 and 8.\n";
  }
  switch(selection){
    case 1:
    {
      //change rname
      std::string newRName;
      std::cout << "Enter new recipe name: ";
      getline(std::cin, newRName);
      target->setRecipeName(newRName);
      target->printRecipeName();
      break;
    }
    case 2:
    {
      //change ctime
      int newCTime;
      std::string userInput;
      target->printCookingTime();
      std::cout << "Enter new cooking time: ";
      while(true){
        getline(std::cin, userInput);
        std::stringstream myStream(userInput);
        if (myStream >> newCTime){
          break;
        }
        std::cout << "Invalid input. Enter a number.\n";
      }
      target->setCookingTime(newCTime);
      target->printCookingTime();
      break;
    }
    case 3:
    {
      //change ptime
      int newPTime;
      std::string userInput;
      target->printPreparationTime();
      std::cout << "Enter new preparation time: ";
      while(true){
        getline(std::cin, userInput);
        std::stringstream myStream(userInput);
        if (myStream >> newPTime){
          break;
        }
        std::cout << "Invalid input. Enter a number.\n";
      }
      target->setPreparationTime(newPTime);
      target->printPreparationTime();
      break;
    }
    case 4:
    {
      //insert instruction
      std::string userInput;
      int input;
      int instructionSize = target->getInstructions().size();
      target->printInstructions();
      std::cout << "Select the point where you want to insert your instruction: ";
      while(true){
        getline(std::cin, userInput);
        std::stringstream myStream(userInput);
        if (myStream >> input){
          if (target->getInstructions().size() >= 0){
            if (input >= 0 && input <= instructionSize){
              break;
            }
          }
        }
        std::cout << "Invalid input. Enter a valid number.\n";
      }
      input--;
      std::cout << "Enter the instruction you want to input\n";
      getline(std::cin, userInput);
      target->addInstruction(userInput);

      for (int i = target->getInstructions().size() - 1; i > input; i--){
        target->swapInstruction(i, i - 1);
      }
      target->printInstructions();
      break;
    }
    case 5:
    {
      //remove instruction
      std::string userInput;
      int input;
      int instructionSize = target->getInstructions().size();
      target->printInstructions();
      std::cout << "Select the point where you want to remove your instruction: ";
      while(true){
        getline(std::cin, userInput);
        std::stringstream myStream(userInput);
        if (myStream >> input){
          if (target->getInstructions().size() >= 0){
            if (input >= 0 && input <= instructionSize){
              break;
            }
          }
        }
        std::cout << "Invalid input. Enter a valid number.\n";
      }
      target->removeInstruction(input);
      target->printInstructions();
      break;
    }
    case 6:
    {
      //insert ingredient
      std::string userInput;
      char c = ':';
      target->printIngredients();
      std::cout << "Input ingredient name with amount and unit after a :\n";
      std::cout << "Example: water:10ml\n";
      getline(std::cin, userInput);
      size_t location = userInput.find(c);
      std::string tempName = userInput.substr(0, location);
      std::string tempAmount = userInput.substr(location + 1, userInput.size() - location);
      target->addIngredient(tempName);
      target->addIngredientAmount(tempAmount);
      target->printIngredients();
      break;
    }
    case 7:
    {
      //remove ingredient
      target->printIngredients();
      std::string userInput;
      char c = ':';
      bool found = false;
      std::cout << "Enter name of ingredient and amount you want to remove followed by a :\n";
      while(true){
        std::getline(std::cin, userInput);
        if (userInput.find(c) != -1){
          break;
        }
        std::cout << "Ensure there is a colon when inputting\n";
      }
      size_t location = userInput.find(c);
      std::string tempName = userInput.substr(0, location);

      for (int i = 0; i < target->getIngredient().size(); i++){
        std::cout << target->getIngredient()[i] << std::endl;
        if (target->getIngredient()[i] == tempName){
          target->removeIngredient(i);
          found = true;
          target->printIngredients();
          break;
        }
      }
      if (!found){
        std::cout << "Could not find " << tempName << " in ingredients\n";
      }
      break;
    }

  }
  std::cout << std::endl;
}

void RecipeList::exportRecipe(std::string rName){
  Recipe* currentRecipe = this->getRecipe(rName);
  std::ofstream myFile;
  myFile.open("export.txt", std::ofstream::app);
  myFile << "Recipe Name: " << rName << std::endl;
  myFile << "Preparation Time: " << currentRecipe->getPreparationTime() << std::endl;
  myFile << "Cooking Time: " << currentRecipe->getCookingTime() << std::endl;

  myFile << "\nIngredients:\n";
  for (int ingred = 0; ingred < currentRecipe->getIngredientSize(); ingred++){
    myFile << currentRecipe->getIngredient()[ingred] << ":" << currentRecipe->getIngredientAmount()[ingred] << std::endl;
  }

  myFile << "\nInstructions:\n";
  for (int instruc = 0; instruc < currentRecipe->getInstructions().size(); instruc++){
    myFile << instruc + 1 << ". " << currentRecipe->getInstructions()[instruc] << std::endl;
  }
  // ~ character used to separate recipes
  myFile << "~\n";
  myFile.close();
}

void RecipeList::exportAll(){
  std::ofstream myFile;
  if (!this->listEmpty()){
    myFile.open("export.txt", std::ofstream::app);
    for (int i = 0; i < this->recipeAmount(); i++){
      this->exportRecipe(listRecipe[i].getRecipeName());
    }
    myFile << "END_OF_FILE\n";
    myFile.close();
  }
  else{
    std::cout << "List is empty\n";
  }
}
//getters
int RecipeList::recipeAmount(){
  return listRecipe.size();
}

bool RecipeList::listEmpty(){
  return listRecipe.empty();
}

Recipe* RecipeList::getCurrentRecipe(){
  if (current == NULL){
    throw "current recipe NULL";
  }
  return current;
}

Recipe* RecipeList::getRecipe(std::string rName){
  for (int i = 0; i < listRecipe.size(); i++){
    if (listRecipe[i].getRecipeName() == rName){
      return &(listRecipe[i]);
    }
  }
}

void RecipeList::printRecipeNames(){
  std::cout << "Available Recipes" << std::endl;
  for (int i = 0; i < listRecipe.size(); i++){
    std::cout << "ListRecipe positon " << i << " contains " << listRecipe[i].getRecipeName() << std::endl;
  }
  std::cout << std::endl;
}

Recipe* RecipeList::findByIngredient(std::string ingr){
  Recipe* results[listRecipe.size()];
  std::vector<Recipe> resList;
  for (int i = 0; i < listRecipe.size(); i++){
    for (int j = 0; j < listRecipe[i].getIngredient().size(); j++){
      if(listRecipe[i].getIngredient()[j] == ingr){
        std::cout << "Found ingredient in: " << listRecipe[i].getRecipeName() << std::endl;
        resList.push_back(listRecipe[i]);
      }
    }
  }
}

void RecipeList::importRecipe(std::string rName){
  int pTime;
  int cTime;
  int colonPos;
  int dotPos;

  std::ifstream myFile;
  std::string line;
  std::string tester = "Recipe Name: ";
  tester.append(rName);
  myFile.open("import.txt", std::ifstream::in);
  getline(myFile, line);

  //Searching for specified recipe
  while(line != tester){
    if(line == tester){
      break;
    }
    getline(myFile, line);
  }
  //At this point, reached the specified recipe

  //Read in pTime
  getline(myFile, line);
  line = line.substr(18, line.size() - 18);
  std::stringstream(line) >> pTime;

  //Read in cTime
  getline(myFile, line);
  line = line.substr(14, line.size() - 14);
  std::stringstream(line) >> cTime;

  //Skipping lines until ingredients
  getline(myFile, line);
  getline(myFile, line);
  getline(myFile, line);

  //Create Recipe object with parameters from above
  Recipe* tempRecipe = new Recipe(rName, cTime, pTime);

  //Getting ingredient + amount
  while(true){
    if (line == ""){
      break;
    }
    colonPos = line.find(":");
    std::cout << "Line: " << line << std::endl;
    tempRecipe->addIngredient(line.substr(0, colonPos));
    tempRecipe->addIngredientAmount(line.substr(colonPos + 1, line.size() - colonPos - 1));
    getline(myFile, line);
  }
  getline(myFile, line);
  getline(myFile, line);

  //Getting instructions
  while(true){
    if (line == "~"){
      break;
    }
    dotPos = line.find(".");
    tempRecipe->addInstruction(line.substr(dotPos + 2, line.size() - dotPos + 2));
    getline(myFile, line);
  }
  listRecipe.push_back(*tempRecipe);
  myFile.close();
}
void RecipeList::importAll(){
  std::string rName;
  int pTime;
  int cTime;

  int colonPos;
  int dotPos;

  std::ifstream myFile;
  std::string line;
  myFile.open("import.txt", std::ifstream::in);
  getline(myFile, line);
  while(true){
    if (line == "END_OF_FILE"){
      break;
    }
    rName = line.substr(13, line.size() - 13);
    //Read in pTime
    getline(myFile, line);
    line = line.substr(18, line.size() - 18);
    std::stringstream(line) >> pTime;

    //Read in cTime
    getline(myFile, line);
    line = line.substr(14, line.size() - 14);
    std::stringstream(line) >> cTime;

    //Skipping lines until ingredients
    getline(myFile, line);
    getline(myFile, line);
    getline(myFile, line);

    //Create Recipe object with parameters from above
    Recipe* tempRecipe = new Recipe(rName, cTime, pTime);

    //Getting ingredient + amount
    while(true){
      if (line == ""){
        break;
      }
      colonPos = line.find(":");
      tempRecipe->addIngredient(line.substr(0, colonPos));
      tempRecipe->addIngredientAmount(line.substr(colonPos + 1, line.size() - colonPos - 1));
      getline(myFile, line);
    }
    getline(myFile, line);
    getline(myFile, line);

    //Getting instructions
    while(true){
      if (line == "~"){
        break;
      }
      dotPos = line.find(".");
      tempRecipe->addInstruction(line.substr(dotPos + 2, line.size() - dotPos + 2));
      getline(myFile, line);
    }
    listRecipe.push_back(*tempRecipe);
    getline(myFile, line);
  }
  myFile.close();
}

bool RecipeList::findRecipe(std::string rName){
  for (int i = 0; i < listRecipe.size(); i++){
    if (listRecipe[i].getRecipeName() == rName){
      return true;
    }
  }
  return false;
}
void RecipeList::printRecipe(std::string rName){
  Recipe* target = this->getRecipe(rName);
  target->printRecipeName();
  target->printCookingTime();
  target->printPreparationTime();
  target->printIngredients();
  target->printInstructions();
}

void RecipeList::randomRecipe(){
  srand(time(NULL));
  if (listRecipe.size() > 0){
    int selection = rand() % listRecipe.size();
    std::cout << "rand: " << selection << std::endl;
    Recipe* target = &listRecipe[selection];
    this->printRecipe(target->getRecipeName());
  }
  else{
    std::cout << "No recipes found.\n";
  }
}
