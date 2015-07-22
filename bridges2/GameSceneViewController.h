/*******************************************************************************
 *
 * Copyright 2012 Zack Grossbart
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

#import <UIKit/UIKit.h>
#import "cocos2d.h"
#import "Level.h"
#import "YouWonViewController.h"
#import "LevelController.h"

/**
 * The GameSceneViewController handles the main view of the game.  It has a button bar
 * on the right with a few navigation buttons and passes most of the game playing off to
 * the game scenes.
 */
@interface GameSceneViewController : UIViewController<CCDirectorDelegate,LevelController> {
    UIWindow *window_;
	UINavigationController *navController_;
    
    bool _hasInit;
    IBOutlet UIButton *_undoBtn;
    IBOutlet UILabel *_coinLabel;
    IBOutlet UIImageView *_coinImage;
    IBOutlet UILabel *_levelTitle;
    IBOutlet UIButton *_hintBtn;

}

/**
 * The navigation controller for the views.
 */
@property (readonly) UINavigationController *navController;

/**
 * The Cocos2d director handles drawig the scene.
 */
@property (readonly) CCDirectorIOS *director;

/**
 * The current window.
 */
@property (nonatomic, retain) IBOutlet UIWindow *window;

/**
 * The You Won view shows up after the user has beaten a level.
 */
@property (retain) YouWonViewController *youWonController;

/**
 * This is the index of the level set containing the level
 * that's being played.
 */
@property (readwrite) int set;

/**
 * Show the specified level and make it playable.
 */
-(void)showLevel:(int) set level:(Level*) level;

/**
 * Tapping the home button sends the user back to the menu screen to 
 * choose a new level
 */
-(IBAction)goHomeTapped:(id)sender;

/**
 * Tapping the undo button undoes the last move the player made in 
 * the game scene.
 */
-(IBAction)undoTapped:(id)sender;

-(IBAction)hintTapped:(id)sender;



/**
 * Tapping the refresh button completely reloads the level and resets
 * it to the same state as when you just loaded it.
 */
-(IBAction)refreshTapped:(id)sender;


@end
