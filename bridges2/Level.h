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

#import <Foundation/Foundation.h>
#import "cocos2d.h"
#import "LayerMgr.h"

/**
 * A level is responsible for managing all of the nodes that
 * make up a single level.  It also determines if the player
 * has won the level and loads all of the objects from the 
 * level JSON definition.
 */
@interface Level : NSObject {
    
    @private
    bool _hasCoins;

    
}

/**
 * Create a new level with a set of JSON data describing the
 * level.
 * 
 * @param jsonString the string of JSON data for this level
 * @param fileName the name of the file containing this level data
 * @param fileDate the date this level was last modified.
 * @param levelId the ID of this level within the current level set
 */
-(id) initWithJson:(NSString*) jsonString fileName:(NSString*) fileName fileDate:(NSDate*) date levelId:(NSInteger) levelId;

/**
 * Add the sprites from this level to the specified layer 
 * manager and UIView.
 *
 * @param layerMgr the layer manager to add the sprites too
 * @param view the UIView to add any controls required for 
 *        this level too
 */
-(void) addSprites: (LayerMgr*) layerMgr view:(UIView*) view;

/**
 * Remove all of the sprites and controls this level has added
 * to the level.
 *
 * @param layerMgr the layer manager to remove sprites from
 */
-(void) removeSprites:(LayerMgr*) layerMgr view:(UIView*) view;

/**
 * Unload all of the sprites loaded by this level.  This level removes
 * the sprites from memory and not just from the current view
 */
-(void)unloadSprites;

/**
 * Determines if the player has won the level.  Returns true
 * if the level is won and false otherwise.
 */
-(bool)hasWon;

/** 
 * Determines if the current level uses coins and the level layer
 * should show the coin count.  Returns true if the level uses
 * coins and false otherwise.
 */
-(bool)hasCoins;

/** 
 * The list of river nodes for this level
 */
@property (readonly, retain) NSMutableArray *rivers;

/** 
 * The list of bridge nodes for this level
 */
@property (readonly, retain) NSMutableArray *bridges;

/** 
 * The list of 4-way bridges for this level
 */
@property (readonly, retain) NSMutableArray *bridge4s;

/** 
 * The list of house nodes for this level
 */
@property (readonly, retain) NSMutableArray *houses;

/**
 * The list of subway nodes for this level
 */
@property (readonly, retain) NSMutableArray *subways;

/**
 * The list of teleport nodes for this level
 */
@property (readonly, retain) NSMutableArray *teleports;


/** 
 * The list of labels for this level
 */
@property (readonly, retain) NSMutableArray *labels;

/** 
 * The display name for this level
 */
@property (readonly, retain) NSString *name;

/**
 * The filename name for this level
 */
@property (readonly, retain) NSString *fileName;


/**
 * The number of coins the user starts the level with
 */
@property (readonly) int coins;

/** 
 * The last modified date for this level
 */
@property (readonly, retain) NSDate *date;

/**
 * The tile count for this level.  The default is 28
 */
@property (readonly) int tileCount;

/** 
 * The ID for this level.  The ID is unique to this level in this 
 * level set, but they are reused across level sets.
 */
@property (readonly, retain) NSString *levelId;

/** 
 * The current player position in the level
 */
@property (readonly) CGPoint playerPos;

/**
 * The position of the starting hint
 */
@property (readonly) CGPoint hintPos;

/**
 * The screen shot image of this level used in the menu screens
 */
@property (readwrite, retain) UIImage *screenshot;

@end


