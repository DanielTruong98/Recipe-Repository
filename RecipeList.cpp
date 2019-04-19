#include "RecipeList.h"
#include <fstream>
#include <sstream>

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
      //TODO input string check to ensure a colon is inputted
      if (input == "exit"){
          break;
      }
      size_t location = input.find(c);
      std::string tempName = input.substr(0, location);
      std::string tempAmount = input.substr(location + 1, input.size() - location);
      //std::cout << "tempName: " << tempName << std::endl;
      //std::cout << "tempAmount: " << tempAmount << std::endl;
      if (tempName != "" || tempAmount != ""){
        temp->addIngredient(tempName);
        temp->addIngredientAmount(tempAmount);
      }
    }
    temp->inputInstructions();
    listRecipe.push_back(*temp);
    /*
    if (listRecipe.back().getRecipeName() == rName){
      std::cout << "Successfully pushed back " << rName << std::endl;
    }
    */

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

void RecipeList::exportRecipe(std::string rName){
  Recipe* currentRecipe = this->findRecipe(rName);
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
  myFile.open("export.txt", std::ofstream::app);
  for (int i = 0; i < this->recipeAmount(); i++){
    this->exportRecipe(listRecipe[i].getRecipeName());
  }
  myFile.close();
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

Recipe* RecipeList::findRecipe(std::string rName){
  for (int i = 0; i < listRecipe.size(); i++){
    if (listRecipe[i].getRecipeName() == rName){
      //std::cout << rName << " found in list\n";
      return &(listRecipe[i]);
    }
  }
  std::cout << rName << " not found in list\n";
}

void RecipeList::printRecipeNames(){
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

void RecipeList::importRecipe(){
  std::string rName;
  int pTime;
  int cTime;
  std::string c = ":";
  size_t loc;
  std::ifstream inFile;
  inFile.open("import.txt", std::ifstream::in);
  std::string line;
  getline(inFile, line);
  loc = line.find(c);
  rName = line.substr(loc + 2, line.size() - 12); // 13 is length of Recipe Name: ignore space
  getline(inFile, line);
  loc = line.find(c);
  std::stringstream(line.substr(loc + 1, line.size() - 17)) >> pTime;
  getline(inFile, line);
  loc = line.find(c);
  std::stringstream(line.substr(loc + 1, line.size() - 13)) >> cTime;
  std::cout << "tName: " << rName << std::endl;
  std::cout << "pTime: " << pTime << std::endl;
  std::cout << "cTime: " << cTime << std::endl;
  Recipe* tempRecipe = new Recipe(rName, cTime, pTime);
  getline(inFile, line);
  getline(inFile, line);
  getline(inFile, line);
  while(true){
    if (line.length() == 0){
      break;
    }
    size_t location;
    for (int i = 0; i < line.size(); i++){
      if (line[i] == ':'){
        location = i;
      }
    }
    std::string tempName = line.substr(0, location);
    std::string tempAmount = line.substr(location + 1, line.size() - location -1);
    if (tempName != "" || tempAmount != ""){
      tempRecipe->addIngredient(tempName);
      tempRecipe->addIngredientAmount(tempAmount);
    }
    getline(inFile, line);
  }
  getline(inFile, line);
  getline(inFile, line);
  while(true){
    if (line == "~"){
      break;
    }
    std::cout << "Line: " << line << std::endl;
    std::string instr = line.substr(3, line.size() - 3);
    tempRecipe->addInstruction(instr);
    getline(inFile, line);
    std::cout << "BB\n";
  }
  listRecipe.push_back(*tempRecipe);
  this->printRecipeNames();
  inFile.close();
}

int RecipeList::findColon(std::string var){
  for (int i = 0; i < var.size(); i++){
    if (var[i] == ':'){
      return i;
    }
  }
  return -1;
}
