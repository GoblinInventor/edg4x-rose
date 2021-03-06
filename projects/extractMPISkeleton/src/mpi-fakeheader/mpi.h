/* mpi.h fake header : AUTOGENERATED, DO NOT MODIFY! */

#ifndef __MPI_H__
#define __MPI_H__

#ifdef __cplusplus
extern "C" {
#endif

/* manually added this to make sure we have the struct fields available. */
typedef struct MPI_Status {
    int count;
    int cancelled;
    int MPI_SOURCE;
    int MPI_TAG;
    int MPI_ERROR;
} MPI_Status;

/* type definitions */
typedef int MPI_Datatype;
typedef int MPI_Comm;
typedef int MPI_Group;
typedef int MPI_Win;
typedef struct ADIOI_FileD * MPI_File;
typedef int MPI_Op;
typedef enum MPIR_Topo_type MPIR_Topo_type;
typedef void(*MPI_Handler_function)(MPI_Comm *, int *, ...);
typedef int(*MPI_Comm_copy_attr_function)(MPI_Comm, int, void *, void *, void *, int *);
typedef int(*MPI_Comm_delete_attr_function)(MPI_Comm, int, void *, void *);
typedef int(*MPI_Type_copy_attr_function)(MPI_Datatype, int, void *, void *, void *, int *);
typedef int(*MPI_Type_delete_attr_function)(MPI_Datatype, int, void *, void *);
typedef int(*MPI_Win_copy_attr_function)(MPI_Win, int, void *, void *, void *, int *);
typedef int(*MPI_Win_delete_attr_function)(MPI_Win, int, void *, void *);
typedef void(*MPI_Comm_errhandler_function)(MPI_Comm *, int *, ...);
typedef void(*MPI_File_errhandler_function)(MPI_File *, int *, ...);
typedef void(*MPI_Win_errhandler_function)(MPI_Win *, int *, ...);
typedef MPI_Comm_errhandler_function MPI_Comm_errhandler_fn;
typedef MPI_File_errhandler_function MPI_File_errhandler_fn;
typedef MPI_Win_errhandler_function MPI_Win_errhandler_fn;
typedef int MPI_Errhandler;
typedef int MPI_Request;
typedef void(*MPI_User_function)(void *, void *, int *, MPI_Datatype *);
typedef int(*MPI_Copy_function)(MPI_Comm, int, void *, void *, void *, int *);
typedef int(*MPI_Delete_function)(MPI_Comm, int, void *, void *);
typedef int MPI_Info;
typedef int MPI_Aint;
typedef int MPI_Fint;
typedef long long MPI_Offset;
typedef int(*MPI_Grequest_cancel_function)(void *, int);
typedef int(*MPI_Grequest_free_function)(void *);
typedef int(*MPI_Grequest_query_function)(void *, MPI_Status *);
typedef int(*MPI_Datarep_conversion_function)(void *, MPI_Datatype, int, void *, MPI_Offset, void *);
typedef int(*MPI_Datarep_extent_function)(MPI_Datatype, MPI_Aint *, void *);
typedef int(*MPIX_Grequest_poll_function)(void *, MPI_Status *);
typedef int(*MPIX_Grequest_wait_function)(int, void **, double, MPI_Status *);
typedef int MPIX_Grequest_class;

/* macros converted to typed variables. */
int MPI_INCLUDED;
int MPI_IDENT;
int MPI_CONGRUENT;
int MPI_SIMILAR;
int MPI_UNEQUAL;
MPI_Datatype MPI_CHAR;
MPI_Datatype MPI_SIGNED_CHAR;
MPI_Datatype MPI_UNSIGNED_CHAR;
MPI_Datatype MPI_BYTE;
MPI_Datatype MPI_WCHAR;
MPI_Datatype MPI_SHORT;
MPI_Datatype MPI_UNSIGNED_SHORT;
MPI_Datatype MPI_INT;
MPI_Datatype MPI_UNSIGNED;
MPI_Datatype MPI_LONG;
MPI_Datatype MPI_UNSIGNED_LONG;
MPI_Datatype MPI_FLOAT;
MPI_Datatype MPI_DOUBLE;
MPI_Datatype MPI_LONG_DOUBLE;
MPI_Datatype MPI_LONG_LONG_INT;
MPI_Datatype MPI_UNSIGNED_LONG_LONG;
int MPI_LONG_LONG;
MPI_Datatype MPI_PACKED;
MPI_Datatype MPI_LB;
MPI_Datatype MPI_UB;
MPI_Datatype MPI_FLOAT_INT;
MPI_Datatype MPI_DOUBLE_INT;
MPI_Datatype MPI_LONG_INT;
MPI_Datatype MPI_SHORT_INT;
MPI_Datatype MPI_2INT;
MPI_Datatype MPI_LONG_DOUBLE_INT;
MPI_Datatype MPI_COMPLEX;
MPI_Datatype MPI_DOUBLE_COMPLEX;
MPI_Datatype MPI_LOGICAL;
MPI_Datatype MPI_REAL;
MPI_Datatype MPI_DOUBLE_PRECISION;
MPI_Datatype MPI_INTEGER;
MPI_Datatype MPI_2INTEGER;
MPI_Datatype MPI_2REAL;
MPI_Datatype MPI_2DOUBLE_PRECISION;
MPI_Datatype MPI_CHARACTER;
MPI_Datatype MPI_REAL4;
MPI_Datatype MPI_REAL8;
MPI_Datatype MPI_REAL16;
MPI_Datatype MPI_COMPLEX8;
MPI_Datatype MPI_COMPLEX16;
MPI_Datatype MPI_COMPLEX32;
MPI_Datatype MPI_INTEGER1;
MPI_Datatype MPI_INTEGER2;
MPI_Datatype MPI_INTEGER4;
MPI_Datatype MPI_INTEGER8;
MPI_Datatype MPI_INTEGER16;
MPI_Datatype MPI_INT8_T;
MPI_Datatype MPI_INT16_T;
MPI_Datatype MPI_INT32_T;
MPI_Datatype MPI_INT64_T;
MPI_Datatype MPI_UINT8_T;
MPI_Datatype MPI_UINT16_T;
MPI_Datatype MPI_UINT32_T;
MPI_Datatype MPI_UINT64_T;
MPI_Datatype MPI_C_BOOL;
MPI_Datatype MPI_C_FLOAT_COMPLEX;
int MPI_C_COMPLEX;
MPI_Datatype MPI_C_DOUBLE_COMPLEX;
MPI_Datatype MPI_C_LONG_DOUBLE_COMPLEX;
MPI_Datatype MPI_AINT;
MPI_Datatype MPI_OFFSET;
int MPI_TYPECLASS_REAL;
int MPI_TYPECLASS_INTEGER;
int MPI_TYPECLASS_COMPLEX;
MPI_Comm MPI_COMM_WORLD;
MPI_Comm MPI_COMM_SELF;
MPI_Group MPI_GROUP_EMPTY;
MPI_Win MPI_WIN_NULL;
int MPI_FILE_DEFINED;
MPI_File MPI_FILE_NULL;
MPI_Op MPI_MAX;
MPI_Op MPI_MIN;
MPI_Op MPI_SUM;
MPI_Op MPI_PROD;
MPI_Op MPI_LAND;
MPI_Op MPI_BAND;
MPI_Op MPI_LOR;
MPI_Op MPI_BOR;
MPI_Op MPI_LXOR;
MPI_Op MPI_BXOR;
MPI_Op MPI_MINLOC;
MPI_Op MPI_MAXLOC;
MPI_Op MPI_REPLACE;
int MPI_TAG_UB;
int MPI_HOST;
int MPI_IO;
int MPI_WTIME_IS_GLOBAL;
int MPI_UNIVERSE_SIZE;
int MPI_LASTUSEDCODE;
int MPI_APPNUM;
int MPI_WIN_BASE;
int MPI_WIN_SIZE;
int MPI_WIN_DISP_UNIT;
MPI_Comm MPI_COMM_NULL;
MPI_Op MPI_OP_NULL;
MPI_Group MPI_GROUP_NULL;
MPI_Datatype MPI_DATATYPE_NULL;
MPI_Request MPI_REQUEST_NULL;
MPI_Errhandler MPI_ERRHANDLER_NULL;
int MPI_MAX_PROCESSOR_NAME;
int MPI_MAX_ERROR_STRING;
int MPI_MAX_PORT_NAME;
int MPI_MAX_OBJECT_NAME;
int MPI_UNDEFINED;
int MPI_KEYVAL_INVALID;
int MPI_BSEND_OVERHEAD;
void * MPI_BOTTOM;
int * MPI_UNWEIGHTED;
int MPI_PROC_NULL;
int MPI_ANY_SOURCE;
int MPI_ROOT;
int MPI_ANY_TAG;
int MPI_LOCK_EXCLUSIVE;
int MPI_LOCK_SHARED;
MPI_Errhandler MPI_ERRORS_ARE_FATAL;
MPI_Errhandler MPI_ERRORS_RETURN;
MPI_Errhandler MPIR_ERRORS_THROW_EXCEPTIONS;
MPI_Copy_function * MPI_NULL_COPY_FN;
MPI_Delete_function * MPI_NULL_DELETE_FN;
int MPI_DUP_FN;
MPI_Comm_copy_attr_function* MPI_COMM_NULL_COPY_FN;
MPI_Comm_delete_attr_function* MPI_COMM_NULL_DELETE_FN;
MPI_Comm_copy_attr_function * MPI_COMM_DUP_FN;
MPI_Win_copy_attr_function* MPI_WIN_NULL_COPY_FN;
MPI_Win_delete_attr_function* MPI_WIN_NULL_DELETE_FN;
MPI_Win_copy_attr_function* MPI_WIN_DUP_FN;
MPI_Type_copy_attr_function* MPI_TYPE_NULL_COPY_FN;
MPI_Type_delete_attr_function* MPI_TYPE_NULL_DELETE_FN;
MPI_Type_copy_attr_function* MPI_TYPE_DUP_FN;
int MPI_VERSION;
int MPI_SUBVERSION;
int MPICH_NAME;
int MPICH2;
int MPICH_HAS_C2F;
int MPICH2_VERSION;
int MPICH2_NUMVERSION;
int MPICH2_RELEASE_TYPE_ALPHA;
int MPICH2_RELEASE_TYPE_BETA;
int MPICH2_RELEASE_TYPE_RC;
int MPICH2_RELEASE_TYPE_PATCH;
#define MPICH2_CALC_VERSION(MAJOR,MINOR,REVISION,TYPE,PATCH) (((MAJOR) * 10000000) + ((MINOR) * 100000) + ((REVISION) * 1000) + ((TYPE) * 100) + (PATCH))
MPI_Info MPI_INFO_NULL;
int MPI_MAX_INFO_KEY;
int MPI_MAX_INFO_VAL;
int MPI_ORDER_C;
int MPI_ORDER_FORTRAN;
int MPI_DISTRIBUTE_BLOCK;
int MPI_DISTRIBUTE_CYCLIC;
int MPI_DISTRIBUTE_NONE;
int MPI_DISTRIBUTE_DFLT_DARG;
void * MPI_IN_PLACE;
int MPI_MODE_NOCHECK;
int MPI_MODE_NOSTORE;
int MPI_MODE_NOPUT;
int MPI_MODE_NOPRECEDE;
int MPI_MODE_NOSUCCEED;
int MPI_AINT_FMT_DEC_SPEC;
int MPI_AINT_FMT_HEX_SPEC;
int HAVE_MPI_OFFSET;
#define MPI_Comm_c2f(comm) (MPI_Fint)(comm)
#define MPI_Comm_f2c(comm) (MPI_Comm)(comm)
#define MPI_Type_c2f(datatype) (MPI_Fint)(datatype)
#define MPI_Type_f2c(datatype) (MPI_Datatype)(datatype)
#define MPI_Group_c2f(group) (MPI_Fint)(group)
#define MPI_Group_f2c(group) (MPI_Group)(group)
#define MPI_Info_c2f(info) (MPI_Fint)(info)
#define MPI_Info_f2c(info) (MPI_Info)(info)
#define MPI_Request_f2c(request) (MPI_Request)(request)
#define MPI_Request_c2f(request) (MPI_Fint)(request)
#define MPI_Op_c2f(op) (MPI_Fint)(op)
#define MPI_Op_f2c(op) (MPI_Op)(op)
#define MPI_Errhandler_c2f(errhandler) (MPI_Fint)(errhandler)
#define MPI_Errhandler_f2c(errhandler) (MPI_Errhandler)(errhandler)
#define MPI_Win_c2f(win) (MPI_Fint)(win)
#define MPI_Win_f2c(win) (MPI_Win)(win)
#define PMPI_Comm_c2f(comm) (MPI_Fint)(comm)
#define PMPI_Comm_f2c(comm) (MPI_Comm)(comm)
#define PMPI_Type_c2f(datatype) (MPI_Fint)(datatype)
#define PMPI_Type_f2c(datatype) (MPI_Datatype)(datatype)
#define PMPI_Group_c2f(group) (MPI_Fint)(group)
#define PMPI_Group_f2c(group) (MPI_Group)(group)
#define PMPI_Info_c2f(info) (MPI_Fint)(info)
#define PMPI_Info_f2c(info) (MPI_Info)(info)
#define PMPI_Request_f2c(request) (MPI_Request)(request)
#define PMPI_Request_c2f(request) (MPI_Fint)(request)
#define PMPI_Op_c2f(op) (MPI_Fint)(op)
#define PMPI_Op_f2c(op) (MPI_Op)(op)
#define PMPI_Errhandler_c2f(errhandler) (MPI_Fint)(errhandler)
#define PMPI_Errhandler_f2c(errhandler) (MPI_Errhandler)(errhandler)
#define PMPI_Win_c2f(win) (MPI_Fint)(win)
#define PMPI_Win_f2c(win) (MPI_Win)(win)
MPI_Status * MPI_STATUS_IGNORE;
MPI_Status * MPI_STATUSES_IGNORE;
int * MPI_ERRCODES_IGNORE;
int MPIU_DLL_SPEC;
char ** MPI_ARGV_NULL;
char *** MPI_ARGVS_NULL;
int MPI_THREAD_SINGLE;
int MPI_THREAD_FUNNELED;
int MPI_THREAD_SERIALIZED;
int MPI_THREAD_MULTIPLE;
int MPI_SUCCESS;
int MPI_ERR_BUFFER;
int MPI_ERR_COUNT;
int MPI_ERR_TYPE;
int MPI_ERR_TAG;
int MPI_ERR_COMM;
int MPI_ERR_RANK;
int MPI_ERR_ROOT;
int MPI_ERR_TRUNCATE;
int MPI_ERR_GROUP;
int MPI_ERR_OP;
int MPI_ERR_REQUEST;
int MPI_ERR_TOPOLOGY;
int MPI_ERR_DIMS;
int MPI_ERR_ARG;
int MPI_ERR_OTHER;
int MPI_ERR_UNKNOWN;
int MPI_ERR_INTERN;
int MPI_ERR_IN_STATUS;
int MPI_ERR_PENDING;
int MPI_ERR_FILE;
int MPI_ERR_ACCESS;
int MPI_ERR_AMODE;
int MPI_ERR_BAD_FILE;
int MPI_ERR_FILE_EXISTS;
int MPI_ERR_FILE_IN_USE;
int MPI_ERR_NO_SPACE;
int MPI_ERR_NO_SUCH_FILE;
int MPI_ERR_IO;
int MPI_ERR_READ_ONLY;
int MPI_ERR_CONVERSION;
int MPI_ERR_DUP_DATAREP;
int MPI_ERR_UNSUPPORTED_DATAREP;
int MPI_ERR_INFO;
int MPI_ERR_INFO_KEY;
int MPI_ERR_INFO_VALUE;
int MPI_ERR_INFO_NOKEY;
int MPI_ERR_NAME;
int MPI_ERR_NO_MEM;
int MPI_ERR_NOT_SAME;
int MPI_ERR_PORT;
int MPI_ERR_QUOTA;
int MPI_ERR_SERVICE;
int MPI_ERR_SPAWN;
int MPI_ERR_UNSUPPORTED_OPERATION;
int MPI_ERR_WIN;
int MPI_ERR_BASE;
int MPI_ERR_LOCKTYPE;
int MPI_ERR_KEYVAL;
int MPI_ERR_RMA_CONFLICT;
int MPI_ERR_RMA_SYNC;
int MPI_ERR_SIZE;
int MPI_ERR_DISP;
int MPI_ERR_ASSERT;
int MPI_ERR_LASTCODE;
int MPICH_ERR_LAST_CLASS;
MPI_Datarep_conversion_function * MPI_CONVERSION_FN_NULL;
int MPIIMPL_ADVERTISES_FEATURES;
int MPIIMPL_HAVE_MPI_INFO;
int MPIIMPL_HAVE_MPI_COMBINER_DARRAY;
int MPIIMPL_HAVE_MPI_TYPE_CREATE_DARRAY;
int MPIIMPL_HAVE_MPI_COMBINER_SUBARRAY;
int MPIIMPL_HAVE_MPI_COMBINER_DUP;
int MPIIMPL_HAVE_MPI_GREQUEST;
int MPIIMPL_HAVE_STATUS_SET_BYTES;
int MPIIMPL_HAVE_STATUS_SET_INFO;

/* function prototypes */
int MPI_Send(void *, int, MPI_Datatype, int, int, MPI_Comm);

int MPI_Recv(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);

int MPI_Get_count(MPI_Status *, MPI_Datatype, int *);

int MPI_Bsend(void *, int, MPI_Datatype, int, int, MPI_Comm);

int MPI_Ssend(void *, int, MPI_Datatype, int, int, MPI_Comm);

int MPI_Rsend(void *, int, MPI_Datatype, int, int, MPI_Comm);

int MPI_Buffer_attach(void *, int);

int MPI_Buffer_detach(void *, int *);

int MPI_Isend(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int MPI_Ibsend(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int MPI_Issend(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int MPI_Irsend(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int MPI_Irecv(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int MPI_Wait(MPI_Request *, MPI_Status *);

int MPI_Test(MPI_Request *, int *, MPI_Status *);

int MPI_Request_free(MPI_Request *);

int MPI_Waitany(int, MPI_Request *, int *, MPI_Status *);

int MPI_Testany(int, MPI_Request *, int *, int *, MPI_Status *);

int MPI_Waitall(int, MPI_Request *, MPI_Status *);

int MPI_Testall(int, MPI_Request *, int *, MPI_Status *);

int MPI_Waitsome(int, MPI_Request *, int *, int *, MPI_Status *);

int MPI_Testsome(int, MPI_Request *, int *, int *, MPI_Status *);

int MPI_Iprobe(int, int, MPI_Comm, int *, MPI_Status *);

int MPI_Probe(int, int, MPI_Comm, MPI_Status *);

int MPI_Cancel(MPI_Request *);

int MPI_Test_cancelled(MPI_Status *, int *);

int MPI_Send_init(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int MPI_Bsend_init(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int MPI_Ssend_init(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int MPI_Rsend_init(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int MPI_Recv_init(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int MPI_Start(MPI_Request *);

int MPI_Startall(int, MPI_Request *);

int MPI_Sendrecv(void *, int, MPI_Datatype, int, int, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);

int MPI_Sendrecv_replace(void *, int, MPI_Datatype, int, int, int, int, MPI_Comm, MPI_Status *);

int MPI_Type_contiguous(int, MPI_Datatype, MPI_Datatype *);

int MPI_Type_vector(int, int, int, MPI_Datatype, MPI_Datatype *);

int MPI_Type_hvector(int, int, MPI_Aint, MPI_Datatype, MPI_Datatype *);

int MPI_Type_indexed(int, int *, int *, MPI_Datatype, MPI_Datatype *);

int MPI_Type_hindexed(int, int *, MPI_Aint *, MPI_Datatype, MPI_Datatype *);

int MPI_Type_struct(int, int *, MPI_Aint *, MPI_Datatype *, MPI_Datatype *);

int MPI_Address(void *, MPI_Aint *);

int MPI_Type_extent(MPI_Datatype, MPI_Aint *);

int MPI_Type_size(MPI_Datatype, int *);

int MPI_Type_lb(MPI_Datatype, MPI_Aint *);

int MPI_Type_ub(MPI_Datatype, MPI_Aint *);

int MPI_Type_commit(MPI_Datatype *);

int MPI_Type_free(MPI_Datatype *);

int MPI_Get_elements(MPI_Status *, MPI_Datatype, int *);

int MPI_Pack(void *, int, MPI_Datatype, void *, int, int *, MPI_Comm);

int MPI_Unpack(void *, int, int *, void *, int, MPI_Datatype, MPI_Comm);

int MPI_Pack_size(int, MPI_Datatype, MPI_Comm, int *);

int MPI_Barrier(MPI_Comm);

int MPI_Bcast(void *, int, MPI_Datatype, int, MPI_Comm);

int MPI_Gather(void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);

int MPI_Gatherv(void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, int, MPI_Comm);

int MPI_Scatter(void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);

int MPI_Scatterv(void *, int *, int *, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);

int MPI_Allgather(void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);

int MPI_Allgatherv(void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);

int MPI_Alltoall(void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);

int MPI_Alltoallv(void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);

int MPI_Reduce(void *, void *, int, MPI_Datatype, MPI_Op, int, MPI_Comm);

int MPI_Op_create(MPI_User_function *, int, MPI_Op *);

int MPI_Op_free(MPI_Op *);

int MPI_Allreduce(void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

int MPI_Reduce_scatter(void *, void *, int *, MPI_Datatype, MPI_Op, MPI_Comm);

int MPI_Scan(void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

int MPI_Group_size(MPI_Group, int *);

int MPI_Group_rank(MPI_Group, int *);

int MPI_Group_translate_ranks(MPI_Group, int, int *, MPI_Group, int *);

int MPI_Group_compare(MPI_Group, MPI_Group, int *);

int MPI_Comm_group(MPI_Comm, MPI_Group *);

int MPI_Group_union(MPI_Group, MPI_Group, MPI_Group *);

int MPI_Group_intersection(MPI_Group, MPI_Group, MPI_Group *);

int MPI_Group_difference(MPI_Group, MPI_Group, MPI_Group *);

int MPI_Group_incl(MPI_Group, int, int *, MPI_Group *);

int MPI_Group_excl(MPI_Group, int, int *, MPI_Group *);

int MPI_Group_range_incl(MPI_Group, int, int (*)[3], MPI_Group *);

int MPI_Group_range_excl(MPI_Group, int, int (*)[3], MPI_Group *);

int MPI_Group_free(MPI_Group *);

int MPI_Comm_size(MPI_Comm, int *);

int MPI_Comm_rank(MPI_Comm, int *);

int MPI_Comm_compare(MPI_Comm, MPI_Comm, int *);

int MPI_Comm_dup(MPI_Comm, MPI_Comm *);

int MPI_Comm_create(MPI_Comm, MPI_Group, MPI_Comm *);

int MPI_Comm_split(MPI_Comm, int, int, MPI_Comm *);

int MPI_Comm_free(MPI_Comm *);

int MPI_Comm_test_inter(MPI_Comm, int *);

int MPI_Comm_remote_size(MPI_Comm, int *);

int MPI_Comm_remote_group(MPI_Comm, MPI_Group *);

int MPI_Intercomm_create(MPI_Comm, int, MPI_Comm, int, int, MPI_Comm *);

int MPI_Intercomm_merge(MPI_Comm, int, MPI_Comm *);

int MPI_Keyval_create(MPI_Copy_function *, MPI_Delete_function *, int *, void *);

int MPI_Keyval_free(int *);

int MPI_Attr_put(MPI_Comm, int, void *);

int MPI_Attr_get(MPI_Comm, int, void *, int *);

int MPI_Attr_delete(MPI_Comm, int);

int MPI_Topo_test(MPI_Comm, int *);

int MPI_Cart_create(MPI_Comm, int, int *, int *, int, MPI_Comm *);

int MPI_Dims_create(int, int, int *);

int MPI_Graph_create(MPI_Comm, int, int *, int *, int, MPI_Comm *);

int MPI_Graphdims_get(MPI_Comm, int *, int *);

int MPI_Graph_get(MPI_Comm, int, int, int *, int *);

int MPI_Cartdim_get(MPI_Comm, int *);

int MPI_Cart_get(MPI_Comm, int, int *, int *, int *);

int MPI_Cart_rank(MPI_Comm, int *, int *);

int MPI_Cart_coords(MPI_Comm, int, int, int *);

int MPI_Graph_neighbors_count(MPI_Comm, int, int *);

int MPI_Graph_neighbors(MPI_Comm, int, int, int *);

int MPI_Cart_shift(MPI_Comm, int, int, int *, int *);

int MPI_Cart_sub(MPI_Comm, int *, MPI_Comm *);

int MPI_Cart_map(MPI_Comm, int, int *, int *, int *);

int MPI_Graph_map(MPI_Comm, int, int *, int *, int *);

int MPI_Get_processor_name(char *, int *);

int MPI_Get_version(int *, int *);

int MPI_Errhandler_create(MPI_Handler_function *, MPI_Errhandler *);

int MPI_Errhandler_set(MPI_Comm, MPI_Errhandler);

int MPI_Errhandler_get(MPI_Comm, MPI_Errhandler *);

int MPI_Errhandler_free(MPI_Errhandler *);

int MPI_Error_string(int, char *, int *);

int MPI_Error_class(int, int *);

double MPI_Wtime(void);

double MPI_Wtick(void);

double PMPI_Wtime(void);

double PMPI_Wtick(void);

int MPI_Init(int *, char ***);

int MPI_Finalize(void);

int MPI_Initialized(int *);

int MPI_Abort(MPI_Comm, int);

int MPI_Pcontrol(const int, ...);

int MPIR_Dup_fn(MPI_Comm, int, void *, void *, void *, int *);

int MPI_Close_port(char *);

int MPI_Comm_accept(char *, MPI_Info, int, MPI_Comm, MPI_Comm *);

int MPI_Comm_connect(char *, MPI_Info, int, MPI_Comm, MPI_Comm *);

int MPI_Comm_disconnect(MPI_Comm *);

int MPI_Comm_get_parent(MPI_Comm *);

int MPI_Comm_join(int, MPI_Comm *);

int MPI_Comm_spawn(char *, char **, int, MPI_Info, int, MPI_Comm, MPI_Comm *, int *);

int MPI_Comm_spawn_multiple(int, char **, char ***, int *, MPI_Info *, int, MPI_Comm, MPI_Comm *, int *);

int MPI_Lookup_name(char *, MPI_Info, char *);

int MPI_Open_port(MPI_Info, char *);

int MPI_Publish_name(char *, MPI_Info, char *);

int MPI_Unpublish_name(char *, MPI_Info, char *);

int MPI_Accumulate(void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op, MPI_Win);

int MPI_Get(void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Win);

int MPI_Put(void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Win);

int MPI_Win_complete(MPI_Win);

int MPI_Win_create(void *, MPI_Aint, int, MPI_Info, MPI_Comm, MPI_Win *);

int MPI_Win_fence(int, MPI_Win);

int MPI_Win_free(MPI_Win *);

int MPI_Win_get_group(MPI_Win, MPI_Group *);

int MPI_Win_lock(int, int, int, MPI_Win);

int MPI_Win_post(MPI_Group, int, MPI_Win);

int MPI_Win_start(MPI_Group, int, MPI_Win);

int MPI_Win_test(MPI_Win, int *);

int MPI_Win_unlock(int, MPI_Win);

int MPI_Win_wait(MPI_Win);

int MPI_Alltoallw(void *, int *, int *, MPI_Datatype *, void *, int *, int *, MPI_Datatype *, MPI_Comm);

int MPI_Exscan(void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

int MPI_Add_error_class(int *);

int MPI_Add_error_code(int, int *);

int MPI_Add_error_string(int, char *);

int MPI_Comm_call_errhandler(MPI_Comm, int);

int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *, MPI_Comm_delete_attr_function *, int *, void *);

int MPI_Comm_delete_attr(MPI_Comm, int);

int MPI_Comm_free_keyval(int *);

int MPI_Comm_get_attr(MPI_Comm, int, void *, int *);

int MPI_Comm_get_name(MPI_Comm, char *, int *);

int MPI_Comm_set_attr(MPI_Comm, int, void *);

int MPI_Comm_set_name(MPI_Comm, char *);

int MPI_File_call_errhandler(MPI_File, int);

int MPI_Grequest_complete(MPI_Request);

int MPI_Grequest_start(MPI_Grequest_query_function *, MPI_Grequest_free_function *, MPI_Grequest_cancel_function *, void *, MPI_Request *);

int MPI_Init_thread(int *, char ***, int, int *);

int MPI_Is_thread_main(int *);

int MPI_Query_thread(int *);

int MPI_Status_set_cancelled(MPI_Status *, int);

int MPI_Status_set_elements(MPI_Status *, MPI_Datatype, int);

int MPI_Type_create_keyval(MPI_Type_copy_attr_function *, MPI_Type_delete_attr_function *, int *, void *);

int MPI_Type_delete_attr(MPI_Datatype, int);

int MPI_Type_dup(MPI_Datatype, MPI_Datatype *);

int MPI_Type_free_keyval(int *);

int MPI_Type_get_attr(MPI_Datatype, int, void *, int *);

int MPI_Type_get_contents(MPI_Datatype, int, int, int, int *, MPI_Aint *, MPI_Datatype *);

int MPI_Type_get_envelope(MPI_Datatype, int *, int *, int *, int *);

int MPI_Type_get_name(MPI_Datatype, char *, int *);

int MPI_Type_set_attr(MPI_Datatype, int, void *);

int MPI_Type_set_name(MPI_Datatype, char *);

int MPI_Type_match_size(int, int, MPI_Datatype *);

int MPI_Win_call_errhandler(MPI_Win, int);

int MPI_Win_create_keyval(MPI_Win_copy_attr_function *, MPI_Win_delete_attr_function *, int *, void *);

int MPI_Win_delete_attr(MPI_Win, int);

int MPI_Win_free_keyval(int *);

int MPI_Win_get_attr(MPI_Win, int, void *, int *);

int MPI_Win_get_name(MPI_Win, char *, int *);

int MPI_Win_set_attr(MPI_Win, int, void *);

int MPI_Win_set_name(MPI_Win, char *);

int MPI_Alloc_mem(MPI_Aint, MPI_Info, void *);

int MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *, MPI_Errhandler *);

int MPI_Comm_get_errhandler(MPI_Comm, MPI_Errhandler *);

int MPI_Comm_set_errhandler(MPI_Comm, MPI_Errhandler);

int MPI_File_create_errhandler(MPI_File_errhandler_function *, MPI_Errhandler *);

int MPI_File_get_errhandler(MPI_File, MPI_Errhandler *);

int MPI_File_set_errhandler(MPI_File, MPI_Errhandler);

int MPI_Finalized(int *);

int MPI_Free_mem(void *);

int MPI_Get_address(void *, MPI_Aint *);

int MPI_Info_create(MPI_Info *);

int MPI_Info_delete(MPI_Info, char *);

int MPI_Info_dup(MPI_Info, MPI_Info *);

int MPI_Info_free(MPI_Info *);

int MPI_Info_get(MPI_Info, char *, int, char *, int *);

int MPI_Info_get_nkeys(MPI_Info, int *);

int MPI_Info_get_nthkey(MPI_Info, int, char *);

int MPI_Info_get_valuelen(MPI_Info, char *, int *, int *);

int MPI_Info_set(MPI_Info, char *, char *);

int MPI_Pack_external(char *, void *, int, MPI_Datatype, void *, MPI_Aint, MPI_Aint *);

int MPI_Pack_external_size(char *, int, MPI_Datatype, MPI_Aint *);

int MPI_Request_get_status(MPI_Request, int *, MPI_Status *);

int MPI_Status_c2f(MPI_Status *, MPI_Fint *);

int MPI_Status_f2c(MPI_Fint *, MPI_Status *);

int MPI_Type_create_darray(int, int, int, int *, int *, int *, int *, int, MPI_Datatype, MPI_Datatype *);

int MPI_Type_create_hindexed(int, int *, MPI_Aint *, MPI_Datatype, MPI_Datatype *);

int MPI_Type_create_hvector(int, int, MPI_Aint, MPI_Datatype, MPI_Datatype *);

int MPI_Type_create_indexed_block(int, int, int *, MPI_Datatype, MPI_Datatype *);

int MPI_Type_create_resized(MPI_Datatype, MPI_Aint, MPI_Aint, MPI_Datatype *);

int MPI_Type_create_struct(int, int *, MPI_Aint *, MPI_Datatype *, MPI_Datatype *);

int MPI_Type_create_subarray(int, int *, int *, int *, int, MPI_Datatype, MPI_Datatype *);

int MPI_Type_get_extent(MPI_Datatype, MPI_Aint *, MPI_Aint *);

int MPI_Type_get_true_extent(MPI_Datatype, MPI_Aint *, MPI_Aint *);

int MPI_Unpack_external(char *, void *, MPI_Aint, MPI_Aint *, void *, int, MPI_Datatype);

int MPI_Win_create_errhandler(MPI_Win_errhandler_function *, MPI_Errhandler *);

int MPI_Win_get_errhandler(MPI_Win, MPI_Errhandler *);

int MPI_Win_set_errhandler(MPI_Win, MPI_Errhandler);

int MPI_Type_create_f90_integer(int, MPI_Datatype *);

int MPI_Type_create_f90_real(int, int, MPI_Datatype *);

int MPI_Type_create_f90_complex(int, int, MPI_Datatype *);

int MPI_Reduce_local(void *, void *, int, MPI_Datatype, MPI_Op);

int MPI_Op_commutative(MPI_Op, int *);

int MPI_Reduce_scatter_block(void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

int MPI_Dist_graph_create_adjacent(MPI_Comm, int, int *, int *, int, int *, int *, MPI_Info, int, MPI_Comm *);

int MPI_Dist_graph_create(MPI_Comm, int, int *, int *, int *, int *, MPI_Info, int, MPI_Comm *);

int MPI_Dist_graph_neighbors_count(MPI_Comm, int *, int *, int *);

int MPI_Dist_graph_neighbors(MPI_Comm, int, int *, int *, int, int *, int *);

int PMPI_Send(void *, int, MPI_Datatype, int, int, MPI_Comm);

int PMPI_Recv(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);

int PMPI_Get_count(MPI_Status *, MPI_Datatype, int *);

int PMPI_Bsend(void *, int, MPI_Datatype, int, int, MPI_Comm);

int PMPI_Ssend(void *, int, MPI_Datatype, int, int, MPI_Comm);

int PMPI_Rsend(void *, int, MPI_Datatype, int, int, MPI_Comm);

int PMPI_Buffer_attach(void *, int);

int PMPI_Buffer_detach(void *, int *);

int PMPI_Isend(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int PMPI_Ibsend(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int PMPI_Issend(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int PMPI_Irsend(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int PMPI_Irecv(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int PMPI_Wait(MPI_Request *, MPI_Status *);

int PMPI_Test(MPI_Request *, int *, MPI_Status *);

int PMPI_Request_free(MPI_Request *);

int PMPI_Waitany(int, MPI_Request *, int *, MPI_Status *);

int PMPI_Testany(int, MPI_Request *, int *, int *, MPI_Status *);

int PMPI_Waitall(int, MPI_Request *, MPI_Status *);

int PMPI_Testall(int, MPI_Request *, int *, MPI_Status *);

int PMPI_Waitsome(int, MPI_Request *, int *, int *, MPI_Status *);

int PMPI_Testsome(int, MPI_Request *, int *, int *, MPI_Status *);

int PMPI_Iprobe(int, int, MPI_Comm, int *, MPI_Status *);

int PMPI_Probe(int, int, MPI_Comm, MPI_Status *);

int PMPI_Cancel(MPI_Request *);

int PMPI_Test_cancelled(MPI_Status *, int *);

int PMPI_Send_init(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int PMPI_Bsend_init(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int PMPI_Ssend_init(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int PMPI_Rsend_init(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int PMPI_Recv_init(void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

int PMPI_Start(MPI_Request *);

int PMPI_Startall(int, MPI_Request *);

int PMPI_Sendrecv(void *, int, MPI_Datatype, int, int, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);

int PMPI_Sendrecv_replace(void *, int, MPI_Datatype, int, int, int, int, MPI_Comm, MPI_Status *);

int PMPI_Type_contiguous(int, MPI_Datatype, MPI_Datatype *);

int PMPI_Type_vector(int, int, int, MPI_Datatype, MPI_Datatype *);

int PMPI_Type_hvector(int, int, MPI_Aint, MPI_Datatype, MPI_Datatype *);

int PMPI_Type_indexed(int, int *, int *, MPI_Datatype, MPI_Datatype *);

int PMPI_Type_hindexed(int, int *, MPI_Aint *, MPI_Datatype, MPI_Datatype *);

int PMPI_Type_struct(int, int *, MPI_Aint *, MPI_Datatype *, MPI_Datatype *);

int PMPI_Address(void *, MPI_Aint *);

int PMPI_Type_extent(MPI_Datatype, MPI_Aint *);

int PMPI_Type_size(MPI_Datatype, int *);

int PMPI_Type_lb(MPI_Datatype, MPI_Aint *);

int PMPI_Type_ub(MPI_Datatype, MPI_Aint *);

int PMPI_Type_commit(MPI_Datatype *);

int PMPI_Type_free(MPI_Datatype *);

int PMPI_Get_elements(MPI_Status *, MPI_Datatype, int *);

int PMPI_Pack(void *, int, MPI_Datatype, void *, int, int *, MPI_Comm);

int PMPI_Unpack(void *, int, int *, void *, int, MPI_Datatype, MPI_Comm);

int PMPI_Pack_size(int, MPI_Datatype, MPI_Comm, int *);

int PMPI_Barrier(MPI_Comm);

int PMPI_Bcast(void *, int, MPI_Datatype, int, MPI_Comm);

int PMPI_Gather(void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);

int PMPI_Gatherv(void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, int, MPI_Comm);

int PMPI_Scatter(void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);

int PMPI_Scatterv(void *, int *, int *, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);

int PMPI_Allgather(void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);

int PMPI_Allgatherv(void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);

int PMPI_Alltoall(void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);

int PMPI_Alltoallv(void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);

int PMPI_Reduce(void *, void *, int, MPI_Datatype, MPI_Op, int, MPI_Comm);

int PMPI_Op_create(MPI_User_function *, int, MPI_Op *);

int PMPI_Op_free(MPI_Op *);

int PMPI_Allreduce(void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

int PMPI_Reduce_scatter(void *, void *, int *, MPI_Datatype, MPI_Op, MPI_Comm);

int PMPI_Scan(void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

int PMPI_Group_size(MPI_Group, int *);

int PMPI_Group_rank(MPI_Group, int *);

int PMPI_Group_translate_ranks(MPI_Group, int, int *, MPI_Group, int *);

int PMPI_Group_compare(MPI_Group, MPI_Group, int *);

int PMPI_Comm_group(MPI_Comm, MPI_Group *);

int PMPI_Group_union(MPI_Group, MPI_Group, MPI_Group *);

int PMPI_Group_intersection(MPI_Group, MPI_Group, MPI_Group *);

int PMPI_Group_difference(MPI_Group, MPI_Group, MPI_Group *);

int PMPI_Group_incl(MPI_Group, int, int *, MPI_Group *);

int PMPI_Group_excl(MPI_Group, int, int *, MPI_Group *);

int PMPI_Group_range_incl(MPI_Group, int, int (*)[3], MPI_Group *);

int PMPI_Group_range_excl(MPI_Group, int, int (*)[3], MPI_Group *);

int PMPI_Group_free(MPI_Group *);

int PMPI_Comm_size(MPI_Comm, int *);

int PMPI_Comm_rank(MPI_Comm, int *);

int PMPI_Comm_compare(MPI_Comm, MPI_Comm, int *);

int PMPI_Comm_dup(MPI_Comm, MPI_Comm *);

int PMPI_Comm_create(MPI_Comm, MPI_Group, MPI_Comm *);

int PMPI_Comm_split(MPI_Comm, int, int, MPI_Comm *);

int PMPI_Comm_free(MPI_Comm *);

int PMPI_Comm_test_inter(MPI_Comm, int *);

int PMPI_Comm_remote_size(MPI_Comm, int *);

int PMPI_Comm_remote_group(MPI_Comm, MPI_Group *);

int PMPI_Intercomm_create(MPI_Comm, int, MPI_Comm, int, int, MPI_Comm *);

int PMPI_Intercomm_merge(MPI_Comm, int, MPI_Comm *);

int PMPI_Keyval_create(MPI_Copy_function *, MPI_Delete_function *, int *, void *);

int PMPI_Keyval_free(int *);

int PMPI_Attr_put(MPI_Comm, int, void *);

int PMPI_Attr_get(MPI_Comm, int, void *, int *);

int PMPI_Attr_delete(MPI_Comm, int);

int PMPI_Topo_test(MPI_Comm, int *);

int PMPI_Cart_create(MPI_Comm, int, int *, int *, int, MPI_Comm *);

int PMPI_Dims_create(int, int, int *);

int PMPI_Graph_create(MPI_Comm, int, int *, int *, int, MPI_Comm *);

int PMPI_Graphdims_get(MPI_Comm, int *, int *);

int PMPI_Graph_get(MPI_Comm, int, int, int *, int *);

int PMPI_Cartdim_get(MPI_Comm, int *);

int PMPI_Cart_get(MPI_Comm, int, int *, int *, int *);

int PMPI_Cart_rank(MPI_Comm, int *, int *);

int PMPI_Cart_coords(MPI_Comm, int, int, int *);

int PMPI_Graph_neighbors_count(MPI_Comm, int, int *);

int PMPI_Graph_neighbors(MPI_Comm, int, int, int *);

int PMPI_Cart_shift(MPI_Comm, int, int, int *, int *);

int PMPI_Cart_sub(MPI_Comm, int *, MPI_Comm *);

int PMPI_Cart_map(MPI_Comm, int, int *, int *, int *);

int PMPI_Graph_map(MPI_Comm, int, int *, int *, int *);

int PMPI_Get_processor_name(char *, int *);

int PMPI_Get_version(int *, int *);

int PMPI_Errhandler_create(MPI_Handler_function *, MPI_Errhandler *);

int PMPI_Errhandler_set(MPI_Comm, MPI_Errhandler);

int PMPI_Errhandler_get(MPI_Comm, MPI_Errhandler *);

int PMPI_Errhandler_free(MPI_Errhandler *);

int PMPI_Error_string(int, char *, int *);

int PMPI_Error_class(int, int *);

int PMPI_Init(int *, char ***);

int PMPI_Finalize(void);

int PMPI_Initialized(int *);

int PMPI_Abort(MPI_Comm, int);

int PMPI_Pcontrol(const int, ...);

int PMPI_Close_port(char *);

int PMPI_Comm_accept(char *, MPI_Info, int, MPI_Comm, MPI_Comm *);

int PMPI_Comm_connect(char *, MPI_Info, int, MPI_Comm, MPI_Comm *);

int PMPI_Comm_disconnect(MPI_Comm *);

int PMPI_Comm_get_parent(MPI_Comm *);

int PMPI_Comm_join(int, MPI_Comm *);

int PMPI_Comm_spawn(char *, char **, int, MPI_Info, int, MPI_Comm, MPI_Comm *, int *);

int PMPI_Comm_spawn_multiple(int, char **, char ***, int *, MPI_Info *, int, MPI_Comm, MPI_Comm *, int *);

int PMPI_Lookup_name(char *, MPI_Info, char *);

int PMPI_Open_port(MPI_Info, char *);

int PMPI_Publish_name(char *, MPI_Info, char *);

int PMPI_Unpublish_name(char *, MPI_Info, char *);

int PMPI_Accumulate(void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op, MPI_Win);

int PMPI_Get(void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Win);

int PMPI_Put(void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Win);

int PMPI_Win_complete(MPI_Win);

int PMPI_Win_create(void *, MPI_Aint, int, MPI_Info, MPI_Comm, MPI_Win *);

int PMPI_Win_fence(int, MPI_Win);

int PMPI_Win_free(MPI_Win *);

int PMPI_Win_get_group(MPI_Win, MPI_Group *);

int PMPI_Win_lock(int, int, int, MPI_Win);

int PMPI_Win_post(MPI_Group, int, MPI_Win);

int PMPI_Win_start(MPI_Group, int, MPI_Win);

int PMPI_Win_test(MPI_Win, int *);

int PMPI_Win_unlock(int, MPI_Win);

int PMPI_Win_wait(MPI_Win);

int PMPI_Alltoallw(void *, int *, int *, MPI_Datatype *, void *, int *, int *, MPI_Datatype *, MPI_Comm);

int PMPI_Exscan(void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

int PMPI_Add_error_class(int *);

int PMPI_Add_error_code(int, int *);

int PMPI_Add_error_string(int, char *);

int PMPI_Comm_call_errhandler(MPI_Comm, int);

int PMPI_Comm_create_keyval(MPI_Comm_copy_attr_function *, MPI_Comm_delete_attr_function *, int *, void *);

int PMPI_Comm_delete_attr(MPI_Comm, int);

int PMPI_Comm_free_keyval(int *);

int PMPI_Comm_get_attr(MPI_Comm, int, void *, int *);

int PMPI_Comm_get_name(MPI_Comm, char *, int *);

int PMPI_Comm_set_attr(MPI_Comm, int, void *);

int PMPI_Comm_set_name(MPI_Comm, char *);

int PMPI_File_call_errhandler(MPI_File, int);

int PMPI_Grequest_complete(MPI_Request);

int PMPI_Grequest_start(MPI_Grequest_query_function *, MPI_Grequest_free_function *, MPI_Grequest_cancel_function *, void *, MPI_Request *);

int PMPI_Init_thread(int *, char ***, int, int *);

int PMPI_Is_thread_main(int *);

int PMPI_Query_thread(int *);

int PMPI_Status_set_cancelled(MPI_Status *, int);

int PMPI_Status_set_elements(MPI_Status *, MPI_Datatype, int);

int PMPI_Type_create_keyval(MPI_Type_copy_attr_function *, MPI_Type_delete_attr_function *, int *, void *);

int PMPI_Type_delete_attr(MPI_Datatype, int);

int PMPI_Type_dup(MPI_Datatype, MPI_Datatype *);

int PMPI_Type_free_keyval(int *);

int PMPI_Type_get_attr(MPI_Datatype, int, void *, int *);

int PMPI_Type_get_contents(MPI_Datatype, int, int, int, int *, MPI_Aint *, MPI_Datatype *);

int PMPI_Type_get_envelope(MPI_Datatype, int *, int *, int *, int *);

int PMPI_Type_get_name(MPI_Datatype, char *, int *);

int PMPI_Type_set_attr(MPI_Datatype, int, void *);

int PMPI_Type_set_name(MPI_Datatype, char *);

int PMPI_Type_match_size(int, int, MPI_Datatype *);

int PMPI_Win_call_errhandler(MPI_Win, int);

int PMPI_Win_create_keyval(MPI_Win_copy_attr_function *, MPI_Win_delete_attr_function *, int *, void *);

int PMPI_Win_delete_attr(MPI_Win, int);

int PMPI_Win_free_keyval(int *);

int PMPI_Win_get_attr(MPI_Win, int, void *, int *);

int PMPI_Win_get_name(MPI_Win, char *, int *);

int PMPI_Win_set_attr(MPI_Win, int, void *);

int PMPI_Win_set_name(MPI_Win, char *);

int PMPI_Type_create_f90_integer(int, MPI_Datatype *);

int PMPI_Type_create_f90_real(int, int, MPI_Datatype *);

int PMPI_Type_create_f90_complex(int, int, MPI_Datatype *);

int PMPI_Alloc_mem(MPI_Aint, MPI_Info, void *);

int PMPI_Comm_create_errhandler(MPI_Comm_errhandler_function *, MPI_Errhandler *);

int PMPI_Comm_get_errhandler(MPI_Comm, MPI_Errhandler *);

int PMPI_Comm_set_errhandler(MPI_Comm, MPI_Errhandler);

int PMPI_File_create_errhandler(MPI_File_errhandler_function *, MPI_Errhandler *);

int PMPI_File_get_errhandler(MPI_File, MPI_Errhandler *);

int PMPI_File_set_errhandler(MPI_File, MPI_Errhandler);

int PMPI_Finalized(int *);

int PMPI_Free_mem(void *);

int PMPI_Get_address(void *, MPI_Aint *);

int PMPI_Info_create(MPI_Info *);

int PMPI_Info_delete(MPI_Info, char *);

int PMPI_Info_dup(MPI_Info, MPI_Info *);

int PMPI_Info_free(MPI_Info *);

int PMPI_Info_get(MPI_Info, char *, int, char *, int *);

int PMPI_Info_get_nkeys(MPI_Info, int *);

int PMPI_Info_get_nthkey(MPI_Info, int, char *);

int PMPI_Info_get_valuelen(MPI_Info, char *, int *, int *);

int PMPI_Info_set(MPI_Info, char *, char *);

int PMPI_Pack_external(char *, void *, int, MPI_Datatype, void *, MPI_Aint, MPI_Aint *);

int PMPI_Pack_external_size(char *, int, MPI_Datatype, MPI_Aint *);

int PMPI_Request_get_status(MPI_Request, int *, MPI_Status *);

int PMPI_Status_c2f(MPI_Status *, MPI_Fint *);

int PMPI_Status_f2c(MPI_Fint *, MPI_Status *);

int PMPI_Type_create_darray(int, int, int, int *, int *, int *, int *, int, MPI_Datatype, MPI_Datatype *);

int PMPI_Type_create_hindexed(int, int *, MPI_Aint *, MPI_Datatype, MPI_Datatype *);

int PMPI_Type_create_hvector(int, int, MPI_Aint, MPI_Datatype, MPI_Datatype *);

int PMPI_Type_create_indexed_block(int, int, int *, MPI_Datatype, MPI_Datatype *);

int PMPI_Type_create_resized(MPI_Datatype, MPI_Aint, MPI_Aint, MPI_Datatype *);

int PMPI_Type_create_struct(int, int *, MPI_Aint *, MPI_Datatype *, MPI_Datatype *);

int PMPI_Type_create_subarray(int, int *, int *, int *, int, MPI_Datatype, MPI_Datatype *);

int PMPI_Type_get_extent(MPI_Datatype, MPI_Aint *, MPI_Aint *);

int PMPI_Type_get_true_extent(MPI_Datatype, MPI_Aint *, MPI_Aint *);

int PMPI_Unpack_external(char *, void *, MPI_Aint, MPI_Aint *, void *, int, MPI_Datatype);

int PMPI_Win_create_errhandler(MPI_Win_errhandler_function *, MPI_Errhandler *);

int PMPI_Win_get_errhandler(MPI_Win, MPI_Errhandler *);

int PMPI_Win_set_errhandler(MPI_Win, MPI_Errhandler);

int PMPI_Reduce_local(void *, void *, int, MPI_Datatype, MPI_Op);

int PMPI_Op_commutative(MPI_Op, int *);

int PMPI_Reduce_scatter_block(void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

int PMPI_Dist_graph_create_adjacent(MPI_Comm, int, int *, int *, int, int *, int *, MPI_Info, int, MPI_Comm *);

int PMPI_Dist_graph_create(MPI_Comm, int, int *, int *, int *, int *, MPI_Info, int, MPI_Comm *);

int PMPI_Dist_graph_neighbors_count(MPI_Comm, int *, int *, int *);

int PMPI_Dist_graph_neighbors(MPI_Comm, int, int *, int *, int, int *, int *);

int MPIX_Grequest_class_create(MPI_Grequest_query_function *, MPI_Grequest_free_function *, MPI_Grequest_cancel_function *, MPIX_Grequest_poll_function *, MPIX_Grequest_wait_function *, MPIX_Grequest_class *);

int MPIX_Grequest_class_allocate(MPIX_Grequest_class, void *, MPI_Request *);

int MPIX_Grequest_start(MPI_Grequest_query_function *, MPI_Grequest_free_function *, MPI_Grequest_cancel_function *, MPIX_Grequest_poll_function *, MPIX_Grequest_wait_function *, void *, MPI_Request *);

int PMPIX_Grequest_class_create(MPI_Grequest_query_function *, MPI_Grequest_free_function *, MPI_Grequest_cancel_function *, MPIX_Grequest_poll_function *, MPIX_Grequest_wait_function *, MPIX_Grequest_class *);

int PMPIX_Grequest_class_allocate(MPIX_Grequest_class, void *, MPI_Request *);

int PMPIX_Grequest_start(MPI_Grequest_query_function *, MPI_Grequest_free_function *, MPI_Grequest_cancel_function *, MPIX_Grequest_poll_function *, MPIX_Grequest_wait_function *, void *, MPI_Request *);

#ifdef __cplusplus
}
#endif

#endif /* __MPI_H__ */
