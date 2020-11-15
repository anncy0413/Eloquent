//
//  FileRepresentation.h
//  Eloquent
//
//  Created by Manfred Bergmann on 15.11.09.
//  Copyright 2009 Software by MABE. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <FooLogger/CocoLogger.h>


@interface FileRepresentation : NSObject {
    NSString *filePath;
    NSFileWrapper *fileWrapper;
    NSMutableDictionary *directoryContentWrapper;
    FileRepresentation *__strong parent;
}

@property (readwrite, strong) NSString *filePath;

+ (FileRepresentation *)createWithName:(NSString *)aName isFolder:(BOOL)isFolder destinationDirectoryRep:(FileRepresentation *)aFolderRep;
+ (BOOL)copyComplete:(FileRepresentation *)source to:(FileRepresentation *)destDirectoryRep;
+ (BOOL)moveComplete:(FileRepresentation *)source to:(FileRepresentation *)destDirectoryRep;
+ (BOOL)deleteComplete:(FileRepresentation *)fileRep;

- (id)initWithPath:(NSString *)aPath;

- (BOOL)isFile;
- (NSString *)name;
- (void)setName:(NSString *)aName;

// regular file methods
- (NSData *)fileContent;
- (void)setFileContent:(NSData *)aData;

// directory methods
- (void)buildTree;
- (BOOL)isDirectory;
- (NSArray *)directoryContent;
- (void)addFileRepresentation:(FileRepresentation *)anItem;
- (void)removeFileRepresentation:(FileRepresentation *)anItem;


@end
