//
//  ModuleViewController.h
//  Eloquent
//
//  Created by Manfred Bergmann on 15.06.08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <FooLogger/CocoLogger.h>

#define TEXT_VERSE_MARKER   @"VerseMarkerAttributeName"

@class SwordModule, CacheObject;

@interface ModuleViewController : ModuleCommonsViewController <NSCoding, TextContentProviding, TextDisplayable, TextDisplayableExt> {
    IBOutlet NSBox *placeHolderView;
    IBOutlet NSTextField *statusLine;
    
    CacheObject *searchContentCache;

    SwordModule *module;
    BOOL performProgressCalculation;
    Indexer *indexer;
}

// --------- properties ---------
@property (strong, readwrite) SwordModule *module;
@property (readwrite) BOOL performProgressCalculation;
@property (strong, readwrite) CacheObject *searchContentCache;

// ---------- methods ---------
- (NSAttributedString *)displayableHTMLForIndexedSearchResults:(NSArray *)results;
- (NSAttributedString *)displayableHTMLForReferenceLookup;

// helper methods for text display/index creation/search result display
// methods maybe overridden to customize handling for subclasses
- (BOOL)hasValidCacheObject;
- (void)handleDisplayForReference;
- (void)handleDisplayIndexedNoHasIndex;
- (void)handleDisplayIndexedPerformSearch;
- (void)handleDisplayCached;
- (void)handleDisplayStatusText;

/**
 populates the modules menu
 to be overriden by subclasses
 */
- (void)populateModulesMenu;

/** abstract method to be overriden by subclasses */
- (void)setStatusText:(NSString *)aText;

// Indexer delegate method
- (void)searchOperationFinished:(NSArray *)results;
// Index creation delegate
- (void)indexCreationFinished:(SwordModule *)mod;
// selector called by menuitems
- (void)moduleSelectionChanged:(id)sender;
/* called then the modules was changed */
- (void)moduleChanged;
// the text view
- (NSTextView *)textView;

// context menu actions
- (IBAction)displayModuleAbout:(id)sender;

@end
