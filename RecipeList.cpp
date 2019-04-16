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
