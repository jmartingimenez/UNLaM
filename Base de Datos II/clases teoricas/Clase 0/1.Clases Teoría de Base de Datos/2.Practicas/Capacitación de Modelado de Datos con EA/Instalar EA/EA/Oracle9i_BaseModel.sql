--Database:			Oracle 9i 
--Source Database:  basemodel
--Date:             12/03/2003
----------------------------------------------
-- Table structure for t_attribute
----------------------------------------------
CREATE TABLE t_attribute (
   Object_ID NUMBER(10) DEFAULT 0 NOT NULL,
   Name VARCHAR2(255) NOT NULL,
   Scope VARCHAR2(50),
   Stereotype VARCHAR2(50),
   Containment VARCHAR2(50),
   IsStatic NUMBER(10) DEFAULT 0,
   IsCollection NUMBER(10) DEFAULT 0,
   IsOrdered NUMBER(10) DEFAULT 0,
   AllowDuplicates NUMBER(10) DEFAULT 0,
   LowerBound VARCHAR2(50),
   UpperBound VARCHAR2(50),
   Container VARCHAR2(50),
   Notes CLOB,
   Derived CHAR(1),
   ID NUMBER(10) PRIMARY KEY,	-- id_seq
   Pos NUMBER(10),
   GenOption CLOB,
   Length NUMBER(10),
   Precision NUMBER(10),
   Scale NUMBER(10),
   Const NUMBER(10),
   Style VARCHAR2(255),
   Classifier VARCHAR2(50),
   "Default" CLOB,
   Type VARCHAR2(255),
   ea_guid VARCHAR2(50),
   StyleEx CLOB
);

CREATE INDEX iattribute ON t_attribute (Object_ID) ;
CREATE INDEX iName ON t_attribute (Name) ;

----------------------------------------------
-- Table structure for t_attributeconstraints
----------------------------------------------
CREATE TABLE t_attributeconstraints (
   Object_ID NUMBER(10) DEFAULT 0,
   "Constraint" VARCHAR2(255),
   AttName VARCHAR2(255),
   Type VARCHAR2(255),
   Notes CLOB,
   ID NUMBER(10),
   PRIMARY KEY(ID, "Constraint")
);

----------------------------------------------
-- Table structure for t_attributetag
----------------------------------------------
CREATE TABLE t_attributetag (
   PropertyID NUMBER(10) PRIMARY KEY, 		-- propertyid_seq
   ElementID NUMBER(10),
   Property VARCHAR2(255),
   VALUE VARCHAR2(255),
   NOTES CLOB,
   ea_guid VARCHAR2(40) 
);

CREATE INDEX ElementKey ON t_attributetag (ElementID);

----------------------------------------------
-- Table structure for t_authors
----------------------------------------------
CREATE TABLE t_authors (
   AuthorName VARCHAR2(255) PRIMARY KEY,
   Roles VARCHAR2(255),
   Notes VARCHAR2(255)
);
   
----------------------------------------------
-- Table structure for t_cardinality
----------------------------------------------
CREATE TABLE t_cardinality (
   Cardinality VARCHAR2(50) PRIMARY KEY
);

----------------------------------------------
-- Table structure for t_category
----------------------------------------------
CREATE TABLE t_category (
   CategoryID NUMBER(10) PRIMARY KEY, 		-- categoryid_seq
   Name VARCHAR2(255),
   Type VARCHAR2(255),
   NOTES CLOB
);

----------------------------------------------
-- Table structure for t_clients
----------------------------------------------
CREATE TABLE t_clients (
   Name VARCHAR2(255) PRIMARY KEY,
   Organisation VARCHAR2(255),
   Phone1 VARCHAR2(50),
   Phone2 VARCHAR2(50),
   Mobile VARCHAR2(50),
   Fax VARCHAR2(50),
   Email VARCHAR2(50),
   Roles VARCHAR2(255),
   Notes VARCHAR2(255)
);

----------------------------------------------
-- Table structure for t_complexitytypes
----------------------------------------------
CREATE TABLE t_complexitytypes (
   Complexity VARCHAR2(50) PRIMARY KEY ,
   NumericWeight NUMBER(10) DEFAULT 0
);

CREATE INDEX NumericWeight ON t_complexitytypes (NumericWeight);

----------------------------------------------
-- Table structure for t_connector
----------------------------------------------
CREATE TABLE t_connector (
   Connector_ID NUMBER(10) PRIMARY KEY,		-- connector_id_seq
   Name VARCHAR2(255),
   Direction VARCHAR2(50),
   Notes CLOB,
   Connector_Type VARCHAR2(50) NOT NULL,
   SubType VARCHAR2(50),
   SourceCard VARCHAR2(50),
   SourceAccess VARCHAR2(50),
   SourceElement VARCHAR2(50),
   DestCard VARCHAR2(50),
   DestAccess VARCHAR2(50),
   DestElement VARCHAR2(50),
   SourceRole VARCHAR2(255),
   SourceRoleType VARCHAR2(50),
   SourceRoleNote CLOB,
   SourceContainment VARCHAR2(50),
   SourceIsAggregate NUMBER(10) DEFAULT '0',
   SourceIsOrdered NUMBER(10) DEFAULT '0',
   SourceQualifier VARCHAR2(50),
   DestRole VARCHAR2(255),
   DestRoleType VARCHAR2(50),
   DestRoleNote CLOB,
   DestContainment VARCHAR2(50),
   DestIsAggregate NUMBER(10) DEFAULT '0',
   DestIsOrdered NUMBER(10) DEFAULT '0',
   DestQualifier VARCHAR2(50),
   Start_Object_ID NUMBER(10) DEFAULT '0' NOT NULL,
   End_Object_ID NUMBER(10) DEFAULT '0' NOT NULL,
   Top_Start_Label VARCHAR2(50),
   Top_Mid_Label VARCHAR2(50),
   Top_End_Label VARCHAR2(50),
   Btm_Start_Label VARCHAR2(50),
   Btm_Mid_Label VARCHAR2(50),
   Btm_End_Label VARCHAR2(50),
   Start_Edge NUMBER(10) DEFAULT '0',
   End_Edge NUMBER(10) DEFAULT '0',
   PtStartX NUMBER(10) DEFAULT '0',
   PtStartY NUMBER(10) DEFAULT '0',
   PtEndX NUMBER(10) DEFAULT '0',
   PtEndY NUMBER(10) DEFAULT '0',
   SeqNo NUMBER(10) DEFAULT '0',
   HeadStyle NUMBER(10) DEFAULT '0',
   LineStyle NUMBER(10) DEFAULT '0',
   RouteStyle NUMBER(10) DEFAULT '0',
   IsBold NUMBER(10) DEFAULT '0',
   LineColor NUMBER(10) DEFAULT '0',
   Stereotype VARCHAR2(50),
   VirtualInheritance CHAR(1),
   LinkAccess VARCHAR2(50),
   PDATA1 VARCHAR2(255),
   PDATA2 VARCHAR2(255),
   PDATA3 VARCHAR2(255),
   PDATA4 VARCHAR2(255),
   PDATA5 VARCHAR2(255),
   DiagramID NUMBER(10) DEFAULT '0' NOT NULL,
   ea_guid VARCHAR2(40) NOT NULL,
   SourceConstraint VARCHAR2(255),
   DestConstraint VARCHAR2(255),
   SourceIsNavigable NUMBER(10),
   DestIsNavigable NUMBER(10),
   IsRoot NUMBER(10),
   IsLeaf NUMBER(10),
   IsSpec NUMBER(10),
   SourceChangeable VARCHAR2(12),
   DestChangeable VARCHAR2(12),
   SourceTS VARCHAR2(12),
   DestTS VARCHAR2(12),
   StateFlags VARCHAR2(255),
   ActionFlags VARCHAR2(255),
   IsSignal NUMBER(10),
   IsStimulus NUMBER(10),
   DispatchAction VARCHAR2(255),
   Target2 NUMBER(10),
   StyleEx CLOB,
   SourceStereotype VARCHAR2(255),
   DestStereotype VARCHAR2(255),
   SourceStyle CLOB,
   DestStyle CLOB,
   EventFlags VARCHAR2(255)
);
      
CREATE UNIQUE INDEX IDX_GUID ON t_connector(ea_guid);   
CREATE INDEX Connector_Type ON t_connector(Connector_Type);
CREATE INDEX DiagramID ON t_connector(DiagramID);
CREATE INDEX End_Object_ID ON t_connector(End_Object_ID);
CREATE INDEX Start_Object_ID ON t_connector(Start_Object_ID);
CREATE INDEX SeqNo ON t_connector(SeqNo);

----------------------------------------------
-- Table structure for t_connectorconstraint
----------------------------------------------
CREATE TABLE t_connectorconstraint (
   ConnectorID NUMBER(10) DEFAULT '0' NOT NULL,
   "Constraint" VARCHAR2(255) NOT NULL,
   ConstraintType VARCHAR2(50),
   Notes CLOB,
   PRIMARY KEY(ConnectorID, "Constraint")
);

CREATE INDEX ObjectConstraintConstraint ON t_connectorconstraint("Constraint");
CREATE INDEX ObjectID ON t_connectorconstraint(ConnectorID);

----------------------------------------------
-- Table structure for t_connectortag
----------------------------------------------
CREATE TABLE t_connectortag (   
   PropertyID NUMBER(10) PRIMARY KEY,		-- propertyid_seq
   ElementID NUMBER(10),
   Property VARCHAR2(255),
   VALUE VARCHAR2(255),
   NOTES CLOB,
   ea_guid VARCHAR2(40)
);

CREATE INDEX ElementIDIdx ON t_connectortag(ElementID);

----------------------------------------------
-- Table structure for t_connectortypes
----------------------------------------------
CREATE TABLE t_connectortypes (
   Connector_Type VARCHAR2(50) PRIMARY KEY,
   Description VARCHAR2(50)
);
   
----------------------------------------------
-- Table structure for t_constants
----------------------------------------------
CREATE TABLE t_constants ( 
	ConstantName VARCHAR2(50) PRIMARY KEY,
	ConstantValue VARCHAR2(255)
);

----------------------------------------------
-- Table structure for t_constrainttypes
----------------------------------------------
CREATE TABLE t_constrainttypes ( 
	"Constraint" VARCHAR2(16) PRIMARY KEY,
	Description VARCHAR2(50),
	Notes CLOB
);

----------------------------------------------
-- Table structure for t_datatypes
----------------------------------------------
CREATE TABLE t_datatypes ( 
	Type VARCHAR2(50) NOT NULL,
	ProductName VARCHAR2(50) NOT NULL,
	DataType VARCHAR2(50) ,
	"Size" NUMBER(10),
	MaxLen NUMBER(10),
	MaxPrec NUMBER(10),
	MaxScale NUMBER(10) DEFAULT 0,
	DefaultLen NUMBER(10),
	DefaultPrec NUMBER(10),
	DefaultScale NUMBER(10),
	"User" NUMBER(10),
	PDATA1 VARCHAR2(255),
	PDATA2 VARCHAR2(255),
	PDATA3 VARCHAR2(255),
	PDATA4 VARCHAR2(255),
	HasLength VARCHAR2(50),
	GenericType VARCHAR2(255),
	DatatypeID NUMBER(10) PRIMARY KEY		-- datatypeid_seq
);

----------------------------------------------
-- Table structure for t_diagram
----------------------------------------------
CREATE TABLE t_diagram ( 
	Diagram_ID NUMBER(10) PRIMARY KEY,		-- diagram_id_seq
	Package_ID NUMBER(10) DEFAULT 1 NOT NULL,
	ParentID NUMBER(10) DEFAULT 0,
	Diagram_Type VARCHAR2(50),
	Name VARCHAR2(255),
	Version VARCHAR2(50) DEFAULT '1.0',
	Author VARCHAR2(255),
	ShowDetails NUMBER(10) DEFAULT 0,
	Notes CLOB,
	Stereotype VARCHAR2(50),
	AttPub NUMBER(10) DEFAULT 1,
	AttPri NUMBER(10) DEFAULT 1,
	AttPro NUMBER(10) DEFAULT 1,
	Orientation CHAR(1) DEFAULT 'P',
	cx NUMBER(10) DEFAULT 0,
	cy NUMBER(10) DEFAULT 0,
	Scale NUMBER(10) DEFAULT 100,
	CreatedDate DATE DEFAULT SYSDATE,
	ModifiedDate DATE DEFAULT SYSDATE,
	HTMLPath VARCHAR2(255),
	ShowForeign NUMBER(10) DEFAULT 1,
	ShowBorder NUMBER(10) DEFAULT 1,
	ShowPackageContents NUMBER(10) DEFAULT 1,
	PDATA VARCHAR2(255),
	Locked NUMBER(10),
	ea_guid VARCHAR2(40) NOT NULL,
	TPos NUMBER(10),
	Swimlanes VARCHAR2(255),
	StyleEx CLOB
);

CREATE UNIQUE INDEX IDX_GUID_DIAGRAM ON t_diagram (ea_guid);
CREATE INDEX Package_ID ON t_diagram (Package_ID);

----------------------------------------------
-- Table structure for t_diagramlinks
----------------------------------------------   
CREATE TABLE t_diagramlinks ( 
	DiagramID NUMBER(10) NOT NULL,
	ConnectorID NUMBER(10) NOT NULL,
	Geometry CLOB,
	Style VARCHAR2(255),
	Hidden NUMBER(10),
	Path VARCHAR2(255),
	Instance_ID NUMBER(10) PRIMARY KEY		-- instance_id_seq
);

CREATE INDEX DiagramIDIdx ON t_diagramlinks (DiagramID);
CREATE INDEX ConnectorID ON t_diagramlinks (ConnectorID);

----------------------------------------------
-- Table structure for t_diagramobjects
----------------------------------------------
CREATE TABLE t_diagramobjects ( 
	Diagram_ID NUMBER(10) DEFAULT 0,
	Object_ID NUMBER(10) DEFAULT 0,
	RectTop NUMBER(10) DEFAULT 0,
	RectLeft NUMBER(10) DEFAULT 0,
	RectRight NUMBER(10) DEFAULT 0,
	RectBottom NUMBER(10) DEFAULT 0,
	Sequence NUMBER(10) DEFAULT 0,
	ObjectStyle VARCHAR2(255),
	Instance_ID NUMBER(10) PRIMARY KEY		-- instance_id_seq
);

CREATE INDEX DiagramID1 ON t_diagramobjects (Diagram_ID);
CREATE INDEX ObjectID1 ON t_diagramobjects (Object_ID);

----------------------------------------------
-- Table structure for t_diagramtypes
----------------------------------------------
CREATE TABLE t_diagramtypes ( 
	Diagram_Type VARCHAR2(50) PRIMARY KEY,
	Name VARCHAR2(255),
	Package_ID NUMBER(10) DEFAULT 0 NOT NULL
);

----------------------------------------------
-- Table structure for t_document
----------------------------------------------
CREATE TABLE t_document ( 
	DocID VARCHAR2(40) PRIMARY KEY,
	DocName VARCHAR2(100),
	Notes VARCHAR2(255),
	Style VARCHAR2(255),
	ElementID VARCHAR2(40) NOT NULL,
	ElementType VARCHAR2(50) NOT NULL,
	StrContent CLOB,
	BinContent BLOB,
	DocType VARCHAR2(100),
	Author VARCHAR2(255),
	Version VARCHAR2(50),
	IsActive NUMBER(10),
	Sequence NUMBER(10),
	DocDate DATE
);

CREATE INDEX ElementID ON t_document (ElementID);

----------------------------------------------
-- Table structure for t_ecf
----------------------------------------------
CREATE TABLE t_ecf ( 
	ECFID VARCHAR2(12) PRIMARY KEY,
	Description VARCHAR2(50),
	Weight FLOAT DEFAULT 1 NOT NULL,
	Value FLOAT DEFAULT 0,
	Notes VARCHAR2(255)
);

CREATE INDEX NumericWeight1 ON t_ecf (Weight);

----------------------------------------------
-- Table structure for t_efforttypes
----------------------------------------------
CREATE TABLE t_efforttypes ( 
	EffortType VARCHAR2(12) PRIMARY KEY,
	Description VARCHAR2(255),
	NumericWeight FLOAT DEFAULT 0 NOT NULL,
	Notes VARCHAR2(255)
);

CREATE INDEX NumericWeight2 ON t_efforttypes (NumericWeight);

----------------------------------------------
-- Table structure for t_files
----------------------------------------------
CREATE TABLE t_files ( 
	FileID VARCHAR2(50) PRIMARY KEY,
	AppliesTo VARCHAR2(100) NOT NULL,
	Category VARCHAR2(50) NOT NULL,
	Name VARCHAR2(150) NOT NULL,
	"File" VARCHAR2(255),
	Notes CLOB,
	FileDate DATE,
	FileSize NUMBER(10)
);

----------------------------------------------
-- Table structure for t_genopt
----------------------------------------------
CREATE TABLE t_genopt ( 
	AppliesTo VARCHAR2(12),
	"Option" CLOB
);

----------------------------------------------
-- Table structure for t_glossary
----------------------------------------------
CREATE TABLE t_glossary ( 
	Term VARCHAR2(255),
	Type VARCHAR2(255),
	Meaning CLOB,
	GlossaryID NUMBER(10) PRIMARY KEY 		-- glossaryid_seq
);

----------------------------------------------
-- Table structure for t_html
----------------------------------------------
CREATE TABLE t_html ( 
	Type VARCHAR2(50),
	Template CLOB
);
	
----------------------------------------------
-- Table structure for t_image
----------------------------------------------
CREATE TABLE t_image ( 
	ImageID NUMBER(10) PRIMARY KEY,		-- imageid_seq
	Name VARCHAR2(255),
	Type VARCHAR2(255),
	Image BLOB
);

----------------------------------------------
-- Table structure for t_implement
----------------------------------------------
CREATE TABLE t_implement ( 
	Type VARCHAR2(50)
);

----------------------------------------------
-- Table structure for t_issues
----------------------------------------------
CREATE TABLE t_issues ( 
	Issue VARCHAR2(255),
	IssueDate DATE,
	Owner VARCHAR2(255),
	Status VARCHAR2(255),
	Notes CLOB,
	Resolver VARCHAR2(255),
	DateResolved DATE,
	Resolution CLOB,
	IssueID NUMBER(10) PRIMARY KEY,		-- issueid_seq
	Category VARCHAR2(255),
	Priority VARCHAR2(100),
	Severity VARCHAR2(50),
	IssueType VARCHAR2(100)
);

----------------------------------------------
-- Table structure for t_lists
----------------------------------------------
CREATE TABLE t_lists ( 
	ListID VARCHAR2(50) PRIMARY KEY,
	Category VARCHAR2(100) NOT NULL,
	Name VARCHAR2(150) NOT NULL,
	NVal NUMBER(10),
	Notes CLOB
);

----------------------------------------------
-- Table structure for t_mainttypes
----------------------------------------------
CREATE TABLE t_mainttypes ( 
	MaintType VARCHAR2(12) PRIMARY KEY,
	Description VARCHAR2(50),
	NumericWeight FLOAT DEFAULT 1 NOT NULL,
	Notes VARCHAR2(255)
);

CREATE INDEX NumericWeight3 ON t_mainttypes (NumericWeight);

----------------------------------------------
-- Table structure for t_method
----------------------------------------------
CREATE TABLE t_method ( 
	Object_ID NUMBER(10) PRIMARY KEY,
	Name VARCHAR2(255) NOT NULL,
	Scope VARCHAR2(50),
	Type VARCHAR2(50)
);

----------------------------------------------
-- Table structure for t_metrictypes
----------------------------------------------
CREATE TABLE t_metrictypes ( 
	Metric VARCHAR2(12) NOT NULL PRIMARY KEY,
	Description VARCHAR2(50),
	NumericWeight FLOAT DEFAULT 1 NOT NULL,
	Notes VARCHAR2(255)
);

CREATE INDEX NumericWeight4 ON t_metrictypes (NumericWeight);

----------------------------------------------
-- Table structure for t_object
----------------------------------------------
CREATE TABLE t_object ( 
	Object_ID NUMBER(10) PRIMARY KEY, 		-- object_id_seq
	Object_Type VARCHAR2(255),
	Diagram_ID NUMBER(10) DEFAULT 0,
	Name VARCHAR2(255),
	Alias VARCHAR2(255),
	Author VARCHAR2(255),
	Version VARCHAR2(50) DEFAULT '1.0',
	Note CLOB,
	Package_ID NUMBER(10) DEFAULT 0 NOT NULL,
	Stereotype VARCHAR2(255),
	NType NUMBER(10) DEFAULT 0,
	Complexity VARCHAR2(50) DEFAULT 2,
	Effort NUMBER(10) DEFAULT 0,
	Style VARCHAR2(255),
	Backcolor NUMBER(10) DEFAULT 0,
	BorderStyle NUMBER(10) DEFAULT 0,
	BorderWidth NUMBER(10) DEFAULT 0,
	Fontcolor NUMBER(10) DEFAULT 0,
	Bordercolor NUMBER(10) DEFAULT 0,
	CreatedDate DATE DEFAULT SYSDATE,
	ModifiedDate DATE DEFAULT SYSDATE,
	Status VARCHAR2(50),
	Abstract CHAR(1),
	Tagged NUMBER(10) DEFAULT 0,
	PDATA1 VARCHAR2(255),
	PDATA2 VARCHAR2(255),
	PDATA3 VARCHAR2(255),
	PDATA4 VARCHAR2(255),
	PDATA5 VARCHAR2(255),
	Concurrency VARCHAR2(50),
	Visibility VARCHAR2(50),
	Persistence VARCHAR2(50),
	Cardinality VARCHAR2(50),
	GenType VARCHAR2(50),
	GenFile VARCHAR2(255),
	Header1 CLOB,
	Header2 CLOB,
	Phase VARCHAR2(50),
	Scope VARCHAR2(25),
	GenOption CLOB,
	GenLinks CLOB,
	Classifier NUMBER(10),
	ea_guid VARCHAR2(40) NOT NULL,
	ParentID NUMBER(10),
	RunState CLOB,
	Classifier_guid VARCHAR2(40),
	TPos NUMBER(10),
	IsRoot NUMBER(10),
	IsLeaf NUMBER(10),
	IsSpec NUMBER(10),
	IsActive NUMBER(10),
	StateFlags VARCHAR2(255),
	PackageFlags VARCHAR2(255),
	Multiplicity VARCHAR2(50),
	StyleEx CLOB,
	ActionFlags VARCHAR2(255),
	EventFlags VARCHAR2(255)
);


CREATE UNIQUE INDEX IDX_GUID_OBJECT ON t_object (ea_guid);
CREATE INDEX Object_Type ON t_object (Object_Type);
CREATE INDEX Classifier ON t_object (Classifier);

----------------------------------------------
-- Table structure for t_objectconstraint
----------------------------------------------
CREATE TABLE t_objectconstraint ( 
	Object_ID NUMBER(10) DEFAULT 0 NOT NULL,
	"Constraint" VARCHAR2(255) NOT NULL,
	ConstraintType VARCHAR2(30) NOT NULL,
	Weight FLOAT DEFAULT 0,
	Notes CLOB,
	Status VARCHAR2(50),
	PRIMARY KEY (Object_ID, "Constraint", ConstraintType)
);

CREATE INDEX ObjectConstraintIdx ON t_objectconstraint ("Constraint");
CREATE INDEX ObjectID2 ON t_objectconstraint (Object_ID);

----------------------------------------------
-- Table structure for t_objecteffort
----------------------------------------------
CREATE TABLE t_objecteffort ( 
	Object_ID NUMBER(10) DEFAULT 0 NOT NULL,
	Effort VARCHAR2(255) NOT NULL,
	EffortType VARCHAR2(12),
	EValue FLOAT DEFAULT 0,
	Notes CLOB,
	PRIMARY KEY (Object_ID, Effort)
);

CREATE INDEX ObjectID3 ON t_objecteffort (Object_ID);

----------------------------------------------
-- Table structure for t_objectfiles
----------------------------------------------
CREATE TABLE t_objectfiles ( 
	Object_ID NUMBER(10) DEFAULT 0 NOT NULL,
	FileName VARCHAR2(255) NOT NULL,
	Type VARCHAR2(50),
	Note CLOB,
	FileSize VARCHAR2(255),
	FileDate VARCHAR2(255),
	PRIMARY KEY (Object_ID, FileName)
);

----------------------------------------------
-- Table structure for t_objectmetrics
----------------------------------------------
CREATE TABLE t_objectmetrics ( 
	Object_ID NUMBER(10) DEFAULT 0 NOT NULL,
	Metric VARCHAR2(255) NOT NULL,
	MetricType VARCHAR2(12) NOT NULL,
	EValue FLOAT DEFAULT 1,
	Notes CLOB,
	PRIMARY KEY (Object_ID, Metric)
);

CREATE INDEX objectmetricsidx ON t_objectmetrics (MetricType);
CREATE INDEX ObjectID4 ON t_objectmetrics (Object_ID);
CREATE INDEX ObjectMetricsMetric ON t_objectmetrics (Metric);

----------------------------------------------
-- Table structure for t_objectproblems
----------------------------------------------
CREATE TABLE t_objectproblems ( 
	Object_ID NUMBER(10) DEFAULT 0 NOT NULL,
	Problem VARCHAR2(255) NOT NULL,
	ProblemType VARCHAR2(200) NOT NULL,
	DateReported DATE,
	Status VARCHAR2(50),
	ProblemNotes CLOB,
	ReportedBy VARCHAR2(255),
	ResolvedBy VARCHAR2(255),
	DateResolved DATE,
	Version VARCHAR2(50),
	ResolverNotes CLOB,
	Priority VARCHAR2(100),
	Severity VARCHAR2(50),
	PRIMARY KEY (Object_ID, Problem, ProblemType)
);

CREATE INDEX ObjectID5 ON t_objectproblems (Object_ID);
CREATE INDEX ObjectRequiresRequirement ON t_objectproblems (Problem);

----------------------------------------------
-- Table structure for t_objectproperties
----------------------------------------------
CREATE TABLE t_objectproperties ( 
	PropertyID NUMBER(10) PRIMARY KEY,		-- propertyid_seq
	Object_ID NUMBER(10) DEFAULT 0 NOT NULL,
	Property VARCHAR2(255),
	Value VARCHAR2(255),
	Notes CLOB,
	ea_guid VARCHAR2(40)
);

CREATE INDEX Object_ID6 ON t_objectproperties (Object_ID);

----------------------------------------------
-- Table structure for t_objectrequires
----------------------------------------------
CREATE TABLE t_objectrequires ( 
	ReqID NUMBER(10) PRIMARY KEY,		-- reqid_seq
	Object_ID NUMBER(10) DEFAULT 0 NOT NULL,
	Requirement VARCHAR2(255),
	ReqType VARCHAR2(255),
	Status VARCHAR2(50),
	Notes CLOB,
	Stability VARCHAR2(50),
	Difficulty VARCHAR2(50),
	Priority VARCHAR2(50),
	LastUpdate VARCHAR2(19) DEFAULT SYSDATE
);

CREATE INDEX ObjectID7 ON t_objectrequires (Object_ID);
CREATE INDEX ObjectRequiresRequirement1 ON t_objectrequires (Requirement);

----------------------------------------------
-- Table structure for t_objectresource
----------------------------------------------
CREATE TABLE t_objectresource ( 
	Object_ID NUMBER(10) DEFAULT 0 NOT NULL,
	"Resource" VARCHAR2(255) NOT NULL,
	Role VARCHAR2(200) NOT NULL,
	Time FLOAT DEFAULT 0,
	Notes CLOB,
	PercentComplete NUMBER(5) DEFAULT 0,
	DateStart DATE,
	DateEnd DATE,
	History CLOB,
	ExpectedHours NUMBER(10),
	ActualHours NUMBER(10),
	PRIMARY KEY (Object_ID, "Resource", Role)
);

CREATE INDEX ObjectID8 ON t_objectresource (Object_ID);

----------------------------------------------
-- Table structure for t_objectrisks
----------------------------------------------
CREATE TABLE t_objectrisks ( 
	Object_ID NUMBER(10) DEFAULT 0 NOT NULL,
	Risk VARCHAR2(255) NOT NULL,
	RiskType VARCHAR2(12),
	EValue FLOAT DEFAULT 0,
	Notes CLOB,
	PRIMARY KEY (Object_ID, Risk) 
);

CREATE INDEX ObjectID9 ON t_objectrisks (Object_ID);

----------------------------------------------
-- Table structure for t_objectscenarios
----------------------------------------------
CREATE TABLE t_objectscenarios ( 
	Object_ID NUMBER(10) DEFAULT 0 NOT NULL,
	Scenario VARCHAR2(255) NOT NULL,
	ScenarioType VARCHAR2(12),
	EValue FLOAT DEFAULT 0,
	Notes CLOB,
	ea_guid VARCHAR2(40) NOT NULL,
	XMLContent CLOB,
	PRIMARY KEY (Object_ID, Scenario) 
);

CREATE INDEX ObjectID10 ON t_objectscenarios (Object_ID);

----------------------------------------------
-- Table structure for t_objecttests
----------------------------------------------
CREATE TABLE t_objecttests ( 
	Object_ID NUMBER(10) DEFAULT 0 NOT NULL,
	Test VARCHAR2(255) NOT NULL,
	TestClass NUMBER(10) DEFAULT 0 NOT NULL,
	TestType VARCHAR2(50),
	Notes CLOB,
	InputData CLOB,
	AcceptanceCriteria CLOB,
	Status VARCHAR2(32),
	DateRun DATE DEFAULT SYSDATE,
	Results CLOB,
	RunBy VARCHAR2(255),
	CheckBy VARCHAR2(255),
	PRIMARY KEY (Object_ID, Test, TestClass)
);

CREATE INDEX ObjectID12 ON t_objecttests (Object_ID);



----------------------------------------------
-- Table structure for t_objecttrx
----------------------------------------------
CREATE TABLE t_objecttrx ( 
	Object_ID NUMBER(10) DEFAULT 0 NOT NULL,
	TRX VARCHAR2(255) NOT NULL,
	TRXType VARCHAR2(12) NOT NULL,
	Weight FLOAT DEFAULT 0,
	Notes CLOB,
	PRIMARY KEY (Object_ID, TRX, TRXType) 
);

CREATE INDEX ObjectConstraintConstraint1 ON t_objecttrx (TRX);
CREATE INDEX ObjectID11 ON t_objecttrx (Object_ID);

----------------------------------------------
-- Table structure for t_objecttypes
----------------------------------------------
CREATE TABLE t_objecttypes ( 
	Object_Type VARCHAR2(50) PRIMARY KEY,
	Description VARCHAR2(255),
	DesignObject NUMBER(10),
	ImageID NUMBER(5) DEFAULT 0 NOT NULL
);

CREATE INDEX ImageID1 ON t_objecttypes (ImageID);

----------------------------------------------
-- Table structure for t_ocf
----------------------------------------------
CREATE TABLE t_ocf ( 
	ObjectType VARCHAR2(50),
	ComplexityWeight FLOAT DEFAULT 0
);

----------------------------------------------
-- Table structure for t_operation
----------------------------------------------
CREATE TABLE t_operation ( 
	OperationID NUMBER(10) PRIMARY KEY,	-- operationid_seq
	Object_ID NUMBER(10) DEFAULT 0 NOT NULL,
	Name VARCHAR2(255) NOT NULL,
	Scope VARCHAR2(50),
	Type VARCHAR2(255),
	ReturnArray CHAR(1),
	Stereotype VARCHAR2(50),
	IsStatic CHAR(1),
	Concurrency VARCHAR2(50),
	Notes CLOB,
	Behaviour CLOB,
	Abstract CHAR(1),
	GenOption CLOB,
	Synchronized CHAR(1),
	Pos NUMBER(10),
	Const NUMBER(10),
	Style VARCHAR2(255),
	Pure NUMBER(10),
	Throws VARCHAR2(255),
	Classifier VARCHAR2(50),
	Code CLOB,
	IsRoot NUMBER(10),
	IsLeaf NUMBER(10),
	IsQuery NUMBER(10),
	StateFlags VARCHAR2(255),
	ea_guid VARCHAR2(40) NOT NULL,
	StyleEx CLOB
);

CREATE INDEX Name ON t_operation (Name);
CREATE INDEX Object_ID7 ON t_operation (Object_ID);

----------------------------------------------
-- Table structure for t_operationparams
----------------------------------------------
CREATE TABLE t_operationparams ( 
	OperationID NUMBER(10) DEFAULT 0 NOT NULL,
	Name VARCHAR2(255) NOT NULL,
	Type VARCHAR2(255),
	"Default" VARCHAR2(255),
	Notes CLOB,
	Pos NUMBER(10) NOT NULL,
	Const NUMBER(10),
	Style VARCHAR2(255),
	Kind VARCHAR2(12),
	Classifier VARCHAR2(50),
	ea_guid VARCHAR2(40),
	StyleEx CLOB,
	PRIMARY KEY (OperationID, Name) 
);

CREATE INDEX OperationID1 ON t_operationparams (OperationID);
CREATE INDEX Param ON t_operationparams (OperationID, Pos);

----------------------------------------------
-- Table structure for t_operationposts
----------------------------------------------
CREATE TABLE t_operationposts ( 
	OperationID NUMBER(10) DEFAULT 0 NOT NULL,
	PostCondition VARCHAR2(255) NOT NULL,
	Type VARCHAR2(255),
	Notes CLOB,
	PRIMARY KEY (OperationID, PostCondition) 
);

CREATE INDEX OperationID2 ON t_operationposts (OperationID);

----------------------------------------------
-- Table structure for t_operationpres
----------------------------------------------
CREATE TABLE t_operationpres ( 
	OperationID NUMBER(10) DEFAULT 0 NOT NULL,
	PreCondition VARCHAR2(255) NOT NULL,
	Type VARCHAR2(50),
	Notes CLOB,
	PRIMARY KEY (OperationID, PreCondition) 
);

CREATE INDEX OperationID3 ON t_operationpres (OperationID);

----------------------------------------------
-- Table structure for t_operationtag
----------------------------------------------
CREATE TABLE t_operationtag ( 
	PropertyID NUMBER(10) PRIMARY KEY,		-- propertyid_seq
	ElementID NUMBER(10) NOT NULL,
	Property VARCHAR2(255),
	VALUE VARCHAR2(255),
	NOTES CLOB,
	ea_guid VARCHAR2(40)
);

CREATE INDEX ElementKey1 ON t_operationtag (ElementID);

----------------------------------------------
-- Table structure for t_package
----------------------------------------------
CREATE TABLE t_package ( 
	Package_ID NUMBER(10) PRIMARY KEY,		-- package_id_seq
	Name VARCHAR2(255),
	Parent_ID NUMBER(10) DEFAULT 0 NOT NULL,
	CreatedDate DATE DEFAULT SYSDATE,
	ModifiedDate DATE DEFAULT SYSDATE,
	Notes CLOB,
	ea_guid VARCHAR2(40) NOT NULL,
	XMLPath VARCHAR2(255),
	IsControlled NUMBER(10),
	LastLoadDate DATE,
	LastSaveDate DATE,
	Version VARCHAR2(50),
	Protected NUMBER(10),
	PkgOwner VARCHAR2(255),
	UMLVersion VARCHAR2(50),
	UseDTD NUMBER(10),
	LogXML NUMBER(10),
	CodePath VARCHAR2(255),
	Namespace VARCHAR2(50),
	TPos NUMBER(10),
	PackageFlags VARCHAR2(255),
	BatchSave NUMBER(10),
	BatchLoad NUMBER(10)
);

CREATE UNIQUE INDEX IDX_GUID_PACKAGE ON t_package (ea_guid);
CREATE INDEX ParentID1 ON t_package (Parent_ID);

----------------------------------------------
-- Table structure for t_palette
----------------------------------------------
CREATE TABLE t_palette ( 
	PaletteID NUMBER(10) UNIQUE,		-- paletteid_seq
	Name VARCHAR2(255),
	Type VARCHAR2(255)
);

----------------------------------------------
-- Table structure for t_paletteitem
----------------------------------------------
CREATE TABLE t_paletteitem ( 
	PaletteID NUMBER(10),
	ItemID NUMBER(10)
);

----------------------------------------------
-- Table structure for t_phase
----------------------------------------------
CREATE TABLE t_phase ( 
	PhaseID VARCHAR2(40) PRIMARY KEY,
	PhaseName VARCHAR2(100) NOT NULL,
	PhaseNotes CLOB,
	PhaseStyle VARCHAR2(255),
	StartDate DATE,
	EndDate DATE,
	PhaseContent CLOB
);

----------------------------------------------
-- Table structure for t_primitives
----------------------------------------------
CREATE TABLE t_primitives ( 
	Datatype VARCHAR2(50) PRIMARY KEY,
	Description VARCHAR2(50)
);

----------------------------------------------
-- Table structure for t_problemtypes
----------------------------------------------
CREATE TABLE t_problemtypes ( 
	ProblemType VARCHAR2(12) PRIMARY KEY,
	Description VARCHAR2(255),
	NumericWeight FLOAT DEFAULT 1 NOT NULL,
	Notes VARCHAR2(255)
);

CREATE INDEX NumericWeight5 ON t_problemtypes (NumericWeight);

----------------------------------------------
-- Table structure for t_projectroles
----------------------------------------------
CREATE TABLE t_projectroles ( 
	Role VARCHAR2(255) PRIMARY KEY,
	Description VARCHAR2(255),
	Notes CLOB
);

----------------------------------------------
-- Table structure for t_propertytypes
----------------------------------------------
CREATE TABLE t_propertytypes ( 
	Property VARCHAR2(50) PRIMARY KEY,
	Description VARCHAR2(50),
	Notes CLOB
);

----------------------------------------------
-- Table structure for t_requiretypes
----------------------------------------------
CREATE TABLE t_requiretypes ( 
	Requirement VARCHAR2(12) PRIMARY KEY,
	Description VARCHAR2(50),
	NumericWeight FLOAT DEFAULT 1 NOT NULL,
	Notes VARCHAR2(255)
);

CREATE INDEX NumericWeight6 ON t_requiretypes (NumericWeight);

----------------------------------------------
-- Table structure for t_resources
----------------------------------------------
CREATE TABLE t_resources ( 
	Name VARCHAR2(255) PRIMARY KEY,
	Organisation VARCHAR2(255),
	Phone1 VARCHAR2(50),
	Phone2 VARCHAR2(50),
	Mobile VARCHAR2(50),
	Fax VARCHAR2(50),
	Email VARCHAR2(255),
	Roles VARCHAR2(255),
	Notes VARCHAR2(255)
);

----------------------------------------------
-- Table structure for t_risktypes
----------------------------------------------
	CREATE TABLE t_risktypes ( 
	Risk VARCHAR2(12) PRIMARY KEY,
	Description VARCHAR2(50),
	NumericWeight FLOAT DEFAULT 0 NOT NULL,
	Notes VARCHAR2(255)
);

CREATE INDEX NumericWeight7 ON t_risktypes (NumericWeight);

----------------------------------------------
-- Table structure for t_roleconstraint
----------------------------------------------
CREATE TABLE t_roleconstraint ( 
	ConnectorID NUMBER(10) DEFAULT 0 NOT NULL,
	Constraint_ VARCHAR2(255) NOT NULL,
	ConnectorEnd VARCHAR2(50) NOT NULL,
	ConstraintType VARCHAR2(12) NOT NULL,
	Notes CLOB,
	PRIMARY KEY (ConnectorID, Constraint_, ConnectorEnd, ConstraintType) 
);

CREATE INDEX ObjectConstraintConstraint2 ON t_roleconstraint (Constraint_);
CREATE INDEX ObjectID13 ON t_roleconstraint (ConnectorID);
   
----------------------------------------------
-- Table structure for t_rtf
----------------------------------------------
CREATE TABLE t_rtf ( 
	Type VARCHAR2(50),
	Template CLOB
);

----------------------------------------------
-- Table structure for t_rtfreport
----------------------------------------------
CREATE TABLE t_rtfreport ( 
	TemplateID VARCHAR2(200) PRIMARY KEY,
	RootPackage NUMBER(10) DEFAULT 0,
	Filename VARCHAR2(255),
	Details NUMBER(10),
	ProcessChildren NUMBER(10),
	ShowDiagrams NUMBER(10),
	Heading VARCHAR2(255),
	Requirements NUMBER(10),
	Associations NUMBER(10),
	Scenarios NUMBER(10),
	ChildDiagrams NUMBER(10),
	Attributes NUMBER(10),
	Methods NUMBER(10),
	ImageType NUMBER(10) DEFAULT 0,
	Paging NUMBER(10),
	Intro CLOB,
	Resources NUMBER(10) DEFAULT 1,
	"Constraints" NUMBER(10) DEFAULT 1,
	Tagged NUMBER(10),
	ShowTag NUMBER(10),
	ShowAlias NUMBER(10),
	PDATA1 VARCHAR2(255),
	PDATA2 VARCHAR2(255),
	PDATA3 VARCHAR2(255),
	PDATA4 CLOB
);

----------------------------------------------
-- Table structure for t_rules
----------------------------------------------
CREATE TABLE t_rules ( 
	RuleID VARCHAR2(50) PRIMARY KEY,
	RuleName VARCHAR2(255) NOT NULL,
	RuleType VARCHAR2(255) NOT NULL,
	RuleActive NUMBER(10) NOT NULL,
	ErrorMsg VARCHAR2(255),
	Flags VARCHAR2(255),
	RuleOCL CLOB,
	RuleXML CLOB,
	Notes CLOB
);

----------------------------------------------
-- Table structure for t_scenariotypes
----------------------------------------------
CREATE TABLE t_scenariotypes ( 
	ScenarioType VARCHAR2(12) PRIMARY KEY,
	Description VARCHAR2(50),
	NumericWeight FLOAT DEFAULT 1 NOT NULL,
	Notes VARCHAR2(255)
);

CREATE INDEX NumericWeight8 ON t_scenariotypes (NumericWeight);

----------------------------------------------
-- Table structure for t_script
----------------------------------------------
CREATE TABLE t_script ( 
	ScriptID NUMBER(10) PRIMARY KEY,		-- scriptid_seq
	ScriptCategory VARCHAR2(100),
	ScriptName VARCHAR2(150),
	ScriptAuthor VARCHAR2(255),
	Notes CLOB,
	Script CLOB
);

----------------------------------------------
-- Table structure for t_secgroup
----------------------------------------------
CREATE TABLE t_secgroup ( 
	GroupID VARCHAR2(40) PRIMARY KEY,
	GroupName VARCHAR2(32) NOT NULL,
	Description VARCHAR2(100)
);

----------------------------------------------
-- Table structure for t_secgrouppermission
----------------------------------------------
CREATE TABLE t_secgrouppermission ( 
	GroupID VARCHAR2(40) NOT NULL,
	PermissionID NUMBER(10) NOT NULL,
	PRIMARY KEY (GroupID, PermissionID) 
);

----------------------------------------------
-- Table structure for t_seclocks
----------------------------------------------
CREATE TABLE t_seclocks ( 
	UserID VARCHAR2(40) NOT NULL,
	GroupID VARCHAR2(40),
	EntityType VARCHAR2(32) NOT NULL,
	EntityID VARCHAR2(40)  PRIMARY KEY,
	Timestamp DATE NOT NULL,
	LockType VARCHAR2(255)
);

----------------------------------------------
-- Table structure for t_secpermission
----------------------------------------------
CREATE TABLE t_secpermission ( 
	PermissionID NUMBER(10) PRIMARY KEY,
	PermissionName VARCHAR2(50) NOT NULL
);

----------------------------------------------
-- Table structure for t_secpolicies
----------------------------------------------
CREATE TABLE t_secpolicies ( 
	Property VARCHAR2(100) PRIMARY KEY,
	Value VARCHAR2(255) NOT NULL
);

----------------------------------------------
-- Table structure for t_secuser
----------------------------------------------
CREATE TABLE t_secuser ( 
	UserID VARCHAR2(40) PRIMARY KEY,
	UserLogin VARCHAR2(32) NOT NULL,
	FirstName VARCHAR2(50) NOT NULL,
	Surname VARCHAR2(50) NOT NULL,
	Department VARCHAR2(50),
	Password VARCHAR2(12)
);

--CREATE UNIQUE INDEX UserID ON t_secuser (UserID);

----------------------------------------------
-- Table structure for t_secusergroup
----------------------------------------------
CREATE TABLE t_secusergroup ( 
	UserID VARCHAR2(40) NOT NULL,
	GroupID VARCHAR2(40) NOT NULL,
	PRIMARY KEY (UserID, GroupID) 
);

----------------------------------------------
-- Table structure for t_secuserpermission
----------------------------------------------
CREATE TABLE t_secuserpermission ( 
	UserID VARCHAR2(40) NOT NULL,
	PermissionID NUMBER(10) NOT NULL,
	PRIMARY KEY (UserID, PermissionID)
);

----------------------------------------------
-- Table structure for t_snapshot
----------------------------------------------
CREATE TABLE t_snapshot ( 
	SnapshotID VARCHAR2(40) PRIMARY KEY,
	SeriesID VARCHAR2(40) NOT NULL,
	Position NUMBER(10) NOT NULL,
	SnapshotName VARCHAR2(100) NOT NULL,
	Notes CLOB,
	Style VARCHAR2(255) NOT NULL,
	ElementID VARCHAR2(40),
	ElementType VARCHAR2(50) NOT NULL,
	StrContent CLOB,
	BinContent1 BLOB,
	BinContent2 BLOB
);

----------------------------------------------
-- Table structure for t_statustypes
----------------------------------------------
CREATE TABLE t_statustypes ( 
	Status VARCHAR2(50) PRIMARY KEY,
	Description VARCHAR2(50)
);


----------------------------------------------
-- Table structure for t_stereotypes
----------------------------------------------
CREATE TABLE t_stereotypes ( 
	Stereotype VARCHAR2(255) NOT NULL,
	AppliesTo VARCHAR2(200) NOT NULL,
	Description VARCHAR2(255),
	MFEnabled NUMBER(10),
	MFPath VARCHAR2(255),
	Metafile BLOB,
	Style CLOB,
	ea_guid VARCHAR2(40) NOT NULL,
	VisualType VARCHAR2(100),
	PRIMARY KEY (Stereotype, AppliesTo) 
);

----------------------------------------------
-- Table structure for t_taggedvalue
----------------------------------------------
CREATE TABLE t_taggedvalue ( 
	PropertyID VARCHAR2(40) PRIMARY KEY,
	ElementID VARCHAR2(40) NOT NULL,
	BaseClass VARCHAR2(50) NOT NULL,
	TagValue CLOB,
	Notes CLOB
);

----------------------------------------------
-- Table structure for t_tasks
----------------------------------------------
CREATE TABLE t_tasks ( 
	TaskID NUMBER(10) PRIMARY KEY,		-- taskid_seq
	Name VARCHAR2(255),
	TaskType VARCHAR2(255),
	NOTES CLOB,
	Priority VARCHAR2(255),
	Status VARCHAR2(255),
	Owner VARCHAR2(255),
	StartDate DATE,
	EndDate DATE,
	Phase VARCHAR2(50),
	History CLOB,
	Percent NUMBER(10),
	TotalTime NUMBER(10),
	ActualTime NUMBER(10),
	AssignedTo VARCHAR2(250)
);

----------------------------------------------
-- Table structure for t_tcf
----------------------------------------------
CREATE TABLE t_tcf ( 
	TCFID VARCHAR2(12) NOT NULL ,
	Description VARCHAR2(50),
	Weight FLOAT DEFAULT 1 NOT NULL,
	Value FLOAT DEFAULT 0,
	Notes VARCHAR2(255)
);

CREATE INDEX NumericWeight9 ON t_tcf (Weight);

----------------------------------------------
-- Table structure for t_template
----------------------------------------------
CREATE TABLE t_template ( 
	TemplateID VARCHAR2(40) PRIMARY KEY,
	TemplateType VARCHAR2(50) NOT NULL,
	TemplateName VARCHAR2(100) NOT NULL,
	Notes VARCHAR2(255),
	Style VARCHAR2(255),
	Template CLOB
);

----------------------------------------------
-- Table structure for t_testclass
----------------------------------------------
CREATE TABLE t_testclass ( 
	TestClass VARCHAR2(50) PRIMARY KEY,
	Description VARCHAR2(50)
);

----------------------------------------------
-- Table structure for t_testplans
----------------------------------------------
CREATE TABLE t_testplans ( 
	PlanID VARCHAR2(50) PRIMARY KEY,
	Category VARCHAR2(100) NOT NULL,
	Name VARCHAR2(100) NOT NULL,
	Author VARCHAR2(255),
	Notes CLOB,
	TestPlan CLOB
);

----------------------------------------------
-- Table structure for t_testtypes
----------------------------------------------
CREATE TABLE t_testtypes ( 
	TestType VARCHAR2(12) PRIMARY KEY,
	Description VARCHAR2(50),
	NumericWeight FLOAT DEFAULT 1 NOT NULL,
	Notes VARCHAR2(255)
);

CREATE INDEX NumericWeight10 ON t_testtypes (NumericWeight);

----------------------------------------------
-- Table structure for t_trxtypes
----------------------------------------------
CREATE TABLE t_trxtypes ( 
	TRX VARCHAR2(255),
	Description VARCHAR2(50),
	NumericWeight FLOAT DEFAULT 1,
	Notes CLOB,
	Style CLOB,
	TRX_ID NUMBER(10) PRIMARY KEY 			-- trx_id_seq
);

CREATE INDEX NumericWeight11 ON t_trxtypes (NumericWeight);

----------------------------------------------
-- Table structure for t_umlpattern
----------------------------------------------
CREATE TABLE t_umlpattern ( 
	PatternID NUMBER(10) PRIMARY KEY,		-- patternid_seq
	PatternCategory VARCHAR2(100),
	PatternName VARCHAR2(150) NOT NULL,
	Style VARCHAR2(250),
	Notes CLOB,
	PatternXML CLOB NOT NULL,
	Version VARCHAR2(50)
);

----------------------------------------------
-- Table structure for t_version
----------------------------------------------
CREATE TABLE t_version ( 
	ElementID VARCHAR2(50) NOT NULL,
	VersionID VARCHAR2(255) NOT NULL,
	ElementType VARCHAR2(100) NOT NULL,
	Flags VARCHAR2(255),
	ExternalFile VARCHAR2(255),
	Notes VARCHAR2(255),
	Owner VARCHAR2(255),
	VersionDate DATE NOT NULL,
	Branch VARCHAR2(255),
	ElementXML CLOB,
	PRIMARY KEY (ElementID, VersionID) 
);

----------------------------------------------
-- Table structure for t_xref
----------------------------------------------
CREATE TABLE t_xref ( 
	XrefID VARCHAR2(255) PRIMARY KEY,
	Name VARCHAR2(255),
	Type VARCHAR2(255) NOT NULL,
	Visibility VARCHAR2(255),
	Namespace VARCHAR2(255),
	Requirement VARCHAR2(255),
	"Constraint" VARCHAR2(255),
	Behavior VARCHAR2(255),
	Partition VARCHAR2(255),
	Description CLOB,
	Client VARCHAR2(255),
	Supplier VARCHAR2(255),
	Link VARCHAR2(255)
);


CREATE INDEX XRefClient ON t_xref (Client);
CREATE INDEX XRefSupplier ON t_xref (Supplier);
CREATE INDEX XRefType ON t_xref (Type);

----------------------------------------------
-- Table structure for t_xrefsystem
----------------------------------------------
CREATE TABLE t_xrefsystem ( 
	XrefID VARCHAR2(255) PRIMARY KEY,
	Name VARCHAR2(255),
	Type VARCHAR2(255) NOT NULL,
	Visibility VARCHAR2(255),
	Namespace VARCHAR2(255),
	Requirement VARCHAR2(255),
	"Constraint" VARCHAR2(255),
	Behavior VARCHAR2(255),
	Partition VARCHAR2(255),
	Description CLOB,
	Client VARCHAR2(255),
	Supplier VARCHAR2(255),
	Link VARCHAR2(255),
	ToolID VARCHAR2(50)
);

CREATE INDEX XRefClient1 ON t_xrefsystem (Client);
CREATE INDEX XRefSupplier1 ON t_xrefsystem (Supplier);
CREATE INDEX XRefType1 ON t_xrefsystem (Type);

----------------------------------------------
-- Table structure for t_xrefuser
----------------------------------------------
CREATE TABLE t_xrefuser ( 
	XrefID VARCHAR2(255) PRIMARY KEY,
	Name VARCHAR2(255),
	Type VARCHAR2(255) NOT NULL,
	Visibility VARCHAR2(255),
	Namespace VARCHAR2(255),
	Requirement VARCHAR2(255),
	"Constraint" VARCHAR2(255),
	Behavior VARCHAR2(255),
	Partition VARCHAR2(255),
	Description CLOB,
	Client VARCHAR2(255),
	Supplier VARCHAR2(255),
	Link VARCHAR2(255),
	ToolID VARCHAR2(50)
);

CREATE INDEX XRefClient2 ON t_xrefuser (Client);
CREATE INDEX XRefSupplier2 ON t_xrefuser (Supplier);
CREATE INDEX XRefType2 ON t_xrefuser (Type);

----------------------------------------------
-- Table structure for usys_system
----------------------------------------------
CREATE TABLE usys_system ( 
	Property VARCHAR2(50) PRIMARY KEY,
	Value VARCHAR2(50)
);

----------------------------------------------
-- Table structure for usysoldtables
----------------------------------------------
CREATE TABLE usysoldtables ( 
	TableName VARCHAR2(50),
	NewName VARCHAR2(50),
	RelOrder NUMBER(10) DEFAULT 0,
	FixCode NUMBER(10)
);

----------------------------------------------
-- Table structure for usysqueries
----------------------------------------------
CREATE TABLE usysqueries ( 
	QueryName VARCHAR2(50),
	NewName VARCHAR2(50),
	FixCode NUMBER(10)
);

----------------------------------------------
-- Table structure for usystables
----------------------------------------------
CREATE TABLE usystables ( 
	TableName VARCHAR2(50) PRIMARY KEY,
	RelOrder NUMBER(10) DEFAULT 0,
	DisplayName VARCHAR2(50),
	FromVer VARCHAR2(50),
	ToVer VARCHAR2(50)
);

