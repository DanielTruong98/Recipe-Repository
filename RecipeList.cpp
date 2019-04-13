#include "RecipeList.h"

//Declaration
RecipeList::RecipeList(){
  currentplace = 0;
}


//setters
void RecipeList::addRecipe(){

    std::string rName;
    int cTime;
    int pTime;
    bool ingredientInput = false;

    std::string input;

    std::cout << "Input recipe name: ";
    std::getline (std::cin, rName);
    std::cout << std::endl;

    std::cout << "Input cooking time: ";
    std::cin >> cTime;
    std::cout << std::endl;

    std::cout << "Input preparation time: ";
    std::cin >> pTime;
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

    while(ingredientInput == false){
      char c = ':';
      std::getline(std::cin, input);
      //TODO input string check to ensure a colon is inputted
      if (input != "exit"){
        size_t location = input.find(c);
        std::string tempName = input.substr(0, location);
        std::string tempAmount = input.substr(location + 1, input.size() - location);
        //std::cout << "tempName: " << tempName << std::endl;
        //std::cout << "tempAmount: " << tempAmount << std::endl;
        temp->addIngredient(tempName);
        temp->addIngredientAmount(tempAmount);
      }
      else{
        ingredientInput = true;
      }
    }
    listRecipe.push_back(*  temp);

    if (listRecipe.back().getRecipeName() == rName){
      std::cout << "Successfully pushed back " << rName << std::endl;
    }


    ///If there is only 1 recipe in the vector
    ///Make it the current recipe
    if (listRecipe.size() == 1){
      //std::cout << "Current size is 1 so setting current to front\n";
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
  std::cout << rName << " not found in list." << std::endl;
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

int RecipeList::findCurrentSpot(int val){

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
